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
int v[130],temp[130],cambios,FrenarMotor=0;

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
int pos=48,lim_izk=47,lim_der=49;
int DIFERENCIA_MINIMA = 30;  //Constante que establece a partir de cuanta diferencia se considera como linea
int RANGO_SEPARACION  = 80;  //Distancia maxima que puede detectarse la linea entre un punto actual y anterior
int ANCHO_PROMEDIO    =  5;  //Total de pixeles a considerar como promedio para la deteccion de la linea

void DetectarLinea()
{
int i,k,suma,sumaTotal,minimo=0,lineas;

cambios=0;
BinarizarImagen();

if(cambios==2 || cambios==6)
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
			lineas=HayLinea(i);
			if(lineas==1) //Verifica que exista 1 maximo a cada lado de la supuesta linea
				{
				minimo=sumaTotal;
				pos=(int)((lim_der-lim_izk)/2.0)+lim_izk;
				//TERMINAL_PRINTF("*%d*",pos-15);
				}
			}
		}
}


/*******************************************************************************************
*  Name                 : BinarizarImagen
*  Description          : Esta funcion...
********************************************************************************************/
void BinarizarImagen()
{
int j;
int minimo=256,maximo=0;

for(j=0 ; j<=127 ; j++) v[j]=temp[j]=0; //Reinicia vector en ceros

for(j=LIM_INICIO ; j<=LIM_FIN ; j++)
	{
	if(LineScanImage0[j]>maximo) maximo=LineScanImage0[j];
	if(LineScanImage0[j]<minimo) minimo=LineScanImage0[j];
	}

for(j=LIM_INICIO ; j<=LIM_FIN ; j++)
	if(LineScanImage0[j] < (maximo-minimo)/4+minimo )		
		v[j]=temp[j]=1;
for(j=LIM_INICIO-1 ; j<=LIM_FIN ; j++)	
	if(v[j]!=v[j+1]) cambios++;

if(v[LIM_INICIO]==1 && v[LIM_FIN]==1) FrenarMotor=1;
else FrenarMotor=0;
/*
for(j=0 ; j<=127; j++)
	{
	if(j==LIM_INICIO || j==LIM_FIN) TERMINAL_PRINTF(" ");
	TERMINAL_PRINTF("%d",v[j]);
	}
TERMINAL_PRINTF("    v[%d]=%d",pos-15,(int)(servomotor[pos-15]));
if(v[LIM_INICIO]==1 && v[LIM_FIN]==1) TERMINAL_PRINTF("  Blanco\n\r");
else TERMINAL_PRINTF("  Linea Negra\n\r");
*/
}


/*******************************************************************************************
*  Name                 : HayDepresion
*  Description          : Esta funcion comprueba que exista una depresion en la linea de valores
*  						  capturada por la camara.
********************************************************************************************/
int HayLinea(int x)
{
int area1=0,area2=0,area3=0;
int j;

if(temp[x]==0) return 0;

//////////////////////////////////////////////////////////////////////
//Checar hacia la IZQUIERDA y contar el area de la linea
j=x;
while(v[j]==1) //Se mueve a el lado izquierdo de la linea
	{
	j--;
	if(j==LIM_INICIO-1) return 0;
	}
j++;
lim_izk=j;
while(v[j]==1) //Empezar a contar el area2 de la linea del lado izquierdo al derecho
	{
	temp[j]=0;
	area2++;
	j++;
	if(j==LIM_FIN+1) return 0;
	}
lim_der=j-1;
while(v[j]==0)
	{
	j++;
	if(j==LIM_FIN+1) break;
	}
while(v[j]==1) //Empezar a contar el area3 de la linea del lado izquierdo al derecho
	{
	temp[j]=0;
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
	temp[j]=0;
	area1++;
	j--;
	}

///////////////////////////////////////////////////////////////////////

if(area2<=5) return 0;  

if(cambios==6 && area1>20 && area3>20)
	{
	TFC_SetBatteryLED_Level(4);
	TFC_HBRIDGE_DISABLE;
	}

//for(j=LIM_INICIO ; j<=LIM_FIN ; j++) TERMINAL_PRINTF("%d",v[j]); 
//TERMINAL_PRINTF("  %d %d %d . v[%d]=%d  %d %d\r\n",area1,area2,area3,pos-15,(int)(servomotor[pos-15]),lim_izk,lim_der);

return 1;
}


void Cesar()
{

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
	
if(FrenarMotor==0)
	{
	TFC_SetMotorPWM(b,a);
	}
else
	{
	if(indice_vector<22) TFC_SetMotorPWM(b,-0.07);
	if(indice_vector>75) TFC_SetMotorPWM(-0.07,a);
	}
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
