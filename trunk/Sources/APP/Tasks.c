/*
 * Freescale Cup Mexico 2013
 * Equipo: CALI
 * 
 */

#include "..\TFC.h"
#define LIM_INICIO	15
#define LIM_FIN 	112


/*******************************************************************************************
*  Name                 : CapturarLineaBase
*  Description          : Esta funcion adquiere la primer imagen que captura la camara
*  						  para poder ser comparada con las demas
********************************************************************************************/
int LineaBase[130];
int LineaBaseMinima[130];

void CapturarLineaBase()
{
int muestras = 10; //Total de imagenes promediadas usadas como base

int i,j;
TFC_SetBatteryLED_Level(1);
while(!TFC_PUSH_BUTTON_1_PRESSED); //Retardo. Presionar Boton B
for(i=0 ; i<muestras ; i++)
	{
	while(LineScanImageReady==0);
	for(j=0 ; j<128 ; j++) LineaBase[j]+=LineScanImage0[j];	
	}
for(j=0 ; j<128 ; j++) LineaBase[j]/=muestras;

TFC_SetBatteryLED_Level(2);
while(!TFC_PUSH_BUTTON_0_PRESSED); //Retardo. Presionar Boton A

for(i=LIM_INICIO ; i<=LIM_FIN ; i++) LineaBaseMinima[i]=255;
TFC_SetBatteryLED_Level(3);
while(!TFC_PUSH_BUTTON_1_PRESSED) //Hasta presionar Boton B	
	if(LineScanImageReady==1)
		{
		LineScanImageReady=0;
		for(i=LIM_INICIO ; i<=LIM_FIN ; i++)
			if(LineScanImage0[i]<LineaBaseMinima[i]) LineaBaseMinima[i]=LineScanImage0[i];
		}
TFC_SetBatteryLED_Level(4);
}


/*******************************************************************************************
*  Name                 : DetectarLinea
*  Description          : Esta funcion obtiene los valores de la camara, recorre los valores
*  						  y determina la maxima diferencia con respecto a 'LineaBase'
********************************************************************************************/
int pos=48;
int DIFERENCIA_MINIMA = 30;  //Constante que establece a partir de cuanta diferencia se considera como linea
int RANGO_SEPARACION  = 80;  //Distancia maxima que puede detectarse la linea entre un punto actual y anterior
int ANCHO_PROMEDIO    =  4;  //Total de pixeles a considerar como promedio para la deteccion de la linea

void DetectarLinea()
{
int i,k,suma,sumaTotal,minimo=0,select;

for(i=LIM_INICIO ; i<=LIM_FIN ; i++) //Se eliminaron 15 pixeles al inicio y al final
	{
	/*Condicion que compara la posicion anterior de la linea con la actual*/
	if(i<(pos-RANGO_SEPARACION) || i>(pos+RANGO_SEPARACION)) //Se encuentra la linea en el rango permitido?
		continue;
	
	/*Ciclo que promedia un rango, donde i es el centro*/	
	sumaTotal=0;
	for(k=i-ANCHO_PROMEDIO ; k<=i+ANCHO_PROMEDIO ; k++)
		{
		if(LineaBase[k]>LineScanImage0[k]) //La linea nueva debe de tener valores menores a la base
			suma=LineaBase[k]-LineScanImage0[k];
		else
			suma=0;
		sumaTotal+=suma;
		}

	sumaTotal=sumaTotal/(ANCHO_PROMEDIO*2+1); //Promedio de la sumaTotal
	
	if(sumaTotal>minimo && sumaTotal>DIFERENCIA_MINIMA) //Es el mayor? Se cumple la diferencia maxima?
		{
		select=HayDepresion(i);
		if(select==1) //Verifica que exista 1 maximo a cada lado de la supuesta linea
			{
			minimo=sumaTotal;
			pos=i;
			}
		else if(select==2) //Detecta que es la meta
			{
			TFC_SetBatteryLED_Level(4);
			TFC_HBRIDGE_DISABLE;
			}
		}
	}
}


/*******************************************************************************************
*  Name                 : HayDepresion
*  Description          : Esta funcion comprueba que exista una depresion en la linea de valores
*  						  capturada por la camara.
********************************************************************************************/
int HayDepresion(int x)
{
int area1=0,area2=0,area3=0;
int j,v[130];

for(j=0 ; j<=127 ; j++) v[j]=0;

for(j=LIM_INICIO ; j<=LIM_FIN ; j++)	
	if(LineScanImage0[j] < ((LineaBase[j]+LineaBaseMinima[j])/2) )		
		v[j]=1;

if(v[x]==0) return 0;

//////////////////////////////////////////////////////////////////////
//Checar hacia la IZQUIERDA y contar el area de la linea
j=x;
while(v[j]==1) //Se mueve a el lado izquierdo de la linea
	{
	j--;
	if(j==LIM_INICIO-1) return 0;
	}
j++;
while(v[j]==1) //Empezar a contar el area2 de la linea del lado izquierdo al derecho
	{
	area2++;
	j++;
	if(j==LIM_FIN+1) return 0;
	}
while(v[j]==0)
	{
	j++;
	if(j==LIM_FIN+1) break;
	}
while(v[j]==1) //Empezar a contar el area3 de la linea del lado izquierdo al derecho
	{
	area3++;
	j++;
	}

//Checar hacia la IZQUIERDA
j=x;
while(v[j]==1) j--;
while(v[j]==0)
	{
	j--;
	if(j==LIM_INICIO-1) break;
	}
while(v[j]==1) //Empezar a contar el area1 de la linea del lado derecho al izquierdo
	{
	area1++;
	j--;
	}

///////////////////////////////////////////////////////////////////////

int s=0;
for(j=LIM_INICIO-1 ; j<=LIM_FIN ; j++)	
	if(v[j]!=v[j+1]) s++;	
if(s!=2 && s!=6) return 0;

if(area2<=8 || area2>=24) return 0;  

if(area1>20 && area3>20)
	{
	TFC_SetBatteryLED_Level(4);
	TFC_HBRIDGE_DISABLE;
	}
/*
for(j=LIM_INICIO ; j<=LIM_FIN ; j++)
	TERMINAL_PRINTF("%d",v[j]);
TERMINAL_PRINTF("  %d %d %d . %d\r\n",area1,area2,area3,InicioMeta);
*/
return 1;
}


/*******************************************************************************************
*  Name                 : ControlDifuso
*  Description          : Esta funcion contiene el control del servomotor
********************************************************************************************/
void ControlDifuso()
{
int indice_vector;
double val;

indice_vector=pos-LIM_INICIO; //Se ajusta pos a valores de [0-97]	
val=(servomotor[indice_vector]*1000/ServoValorMax)/1000.0;
TFC_SetServo(0,val);
}


/*******************************************************************************************
*  Name                 : VelocidadMotor
*  Description          : Esta funcion contiene el control de la velocidad
********************************************************************************************/
void VelocidadMotor()
{
int indice_vector;
float a,b;

indice_vector=pos-LIM_INICIO; //Se ajusta pos a valores de [0-97]
a=motor_izquierdo[indice_vector]/1000.0;
b=motor_derecho[indice_vector]/1000.0;
if(a>TFC_ReadPot1()) a=TFC_ReadPot1();
if(b>TFC_ReadPot1()) b=TFC_ReadPot1();
TFC_SetMotorPWM(b,a);
}

/*******************************************************************************************
*  Name                 : SeguirLineaCamara
*  Description          : Esta funcion obtiene los valores de la camara, recorre los valores
*  						  y determina la maxima diferencia con respecto a 'LineaBase'
********************************************************************************************/
void ControlLineal()
{
TFC_SetServo(0,(float)(((pos-15)/48.5)-1.0));			
}


/*******************************************************************************************
*  Name                 : VoltajeBateria
*  Description          : Esta funcion lee el ADC que se encuentra conectado a la Bateria, 
*  						  de acuerdo a su valor, prende una serie de LEDs 
********************************************************************************************/
void VoltajeBateria()
{
int bateria = BatSenseADC_Value,nivel=1;

if(bateria>=125)		nivel=4;	//Mayor de 8.0 volts
else if(bateria>=121)	nivel=3;	//Mayor de 7.8 volts
else if(bateria>=117)	nivel=2;	//Mayor de 7.6 volts 
else if(bateria>=114)	nivel=1;	//Mayor de 7.4 volts
else if(bateria>=99)	nivel=0;	//Mayor de 6.7 volts
//else if(bateria>=92) 	nivel=0;	//Mayor de 6.2 volts
//else if(bateria>=85) 	nivel=0;	//Mayor de 5.7 volts
//else if(bateria>=77) 	nivel=0;	//Mayor de 5.2 volts
else					nivel=5;	//Menor de 5.2 volts

//TERMINAL_PRINTF("Bat:%d  Nivel:%d\r\n",bateria,nivel);
TFC_SetBatteryLED_Level(nivel);
}


void GraficarLabVIEW()
{
int i;
if(LineScanImageReady==1)
	{
	LineScanImageReady=0;
	
	TERMINAL_PRINTF("\r\n");
	TERMINAL_PRINTF("L:");	
	if(TFC_GetDIP_Switch()&0x08)
		{		
		for(i=0;i<128;i++)
			{
			if(i==0) 							 
				TERMINAL_PRINTF("%X,",pos);
			else
				TERMINAL_PRINTF("%X,",LineaBaseMinima[i]);
			}		
		}
	else
		{
		for(i=0;i<128;i++)
			{
			if(i==0) 							 
				TERMINAL_PRINTF("%X,",pos);
			else
				TERMINAL_PRINTF("%X,",LineScanImage0[i]);
			}		
		}
	
	for(i=0;i<128;i++)
		{	
		TERMINAL_PRINTF("%X",LineaBase[i]);
		if(i==127)
			TERMINAL_PRINTF("\r\n",LineaBase[i]);
		else
			TERMINAL_PRINTF(",",LineaBase[i]);
		}
	}	
}





/*void SeguirLineaQRD1114()
{
if(TFC_SENSOR_1 && TFC_SENSOR_2 && TFC_SENSOR_3 && TFC_SENSOR_4 && TFC_SENSOR_5 && TFC_SENSOR_6 && TFC_SENSOR_7)	
	TFC_SetServo(0,0);			
}*/

/*
int pos=63;
void DetectarLinea()
{
//int ANCHO_PROMEDIO = 10;  //Total de pixeles a considerar como promedio para la deteccion de la linea
int RANGO_SEPARACION = 50;  //Distancia maxima que puede detectarse la linea entre un punto actual y anterior
int DIFERENCIA_MINIMA = 60; //Constante que establece a partir de cuanta diferencia se considera como linea

int i,suma,minimo=0;
for(i=15 ; i<=112 ; i++) //Se eliminaron 15 pixeles al inicio y al final
	{
	
	En esta parte se debe de promediar cierto rango
	
	if(LineaBase[i]>LineScanImage0[i]) //La linea nueva debe de tener valores menores a la base
		suma=LineaBase[i]-LineScanImage0[i];
	else
		suma=0;
	if(suma>minimo && suma>DIFERENCIA_MINIMA) //Es el mayor? Se cumple la diferencia maxima?
		{
		if(i>=(pos-RANGO_SEPARACION) && i<=(pos+RANGO_SEPARACION)) //Se encuentra en el rango?
			{
			minimo=suma;
			pos=i;
			}
		}
	}
} 
*/


/*
int HayDepresion(int x)
{
int area1=0,area2=0,area3=0;
int j,v[130],InicioMeta=0;

for(j=0 ; j<=127 ; j++) v[j]=0;

for(j=LIM_INICIO ; j<=LIM_FIN ; j++)	
	if(LineScanImage0[j] < ((LineaBase[j]+LineaBaseMinima[j])/2) )		
		v[j]=1;

if(v[x]==0) return 0;

//Checar hacia la DERECHA
j=x;
while(v[j]==1) 
	{
	j++;
	if(j==LIM_FIN+1) return 0;
	}

while(v[j]==0) //InicioMeta
	{
	j++;
	if(j==LIM_FIN+1) break;
	}
if(j!=LIM_FIN+1) InicioMeta++;

//Checar hacia la IZQUIERDA
j=x;
while(v[j]==1)
	{	
	j--;
	if(j==LIM_INICIO-1) return 0;
	}

while(v[j]==0) //InicioMeta
	{
	j--;
	if(j==LIM_INICIO-1) break;
	}
if(j!=LIM_INICIO-1) InicioMeta++;

for(j=15 ; j<=112 ; j++)
	TERMINAL_PRINTF("%d",v[j]);
TERMINAL_PRINTF("  %d %d %d\r\n",area1,area2,area3);

if(InicioMeta==2)
	return 2;
else
	return 1;
}
*/