/*
 * Freescale Cup Mexico 2013
 * Equipo: CALI
 * 
 */

#include "..\TFC.h"

/****************************************************************************************************************
*	Vectores constantes obtenidos de la Logica Difusa
****************************************************************************************************************/
short servomotor[1001]={
		 109,
		 109, 109, 109, 110, 110, 110, 110, 110, 111, 111, 111, 111, 111, 112, 112, 112, 112, 113, 113, 113,
		 113, 114, 114, 114, 114, 115, 115, 115, 116, 116, 116, 116, 117, 117, 117, 118, 118, 119, 119, 119,
		 120, 120, 120, 121, 121, 122, 122, 122, 123, 123, 124, 124, 125, 125, 125, 126, 126, 127, 127, 128,
		 128, 129, 129, 130, 130, 131, 131, 132, 132, 133, 133, 134, 135, 135, 136, 136, 137, 137, 138, 139,
		 139, 140, 140, 141, 141, 142, 143, 143, 144, 144, 145, 146, 146, 147, 147, 148, 149, 149, 150, 150,
		 151, 152, 152, 153, 154, 154, 155, 155, 156, 157, 157, 158, 159, 159, 160, 161, 161, 162, 163, 163,
		 164, 165, 165, 166, 167, 167, 168, 169, 169, 170, 171, 171, 172, 173, 173, 174, 175, 175, 176, 177,
		 177, 178, 179, 179, 180, 181, 181, 182, 183, 183, 184, 185, 185, 186, 187, 187, 188, 189, 189, 190,
		 191, 192, 192, 193, 194, 194, 195, 196, 196, 197, 198, 198, 199, 200, 201, 201, 202, 203, 203, 204,
		 205, 206, 206, 207, 208, 209, 209, 210, 211, 212, 213, 213, 214, 215, 216, 216, 217, 218, 219, 220,
		 221, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239,
		 241, 242, 243, 244, 245, 247, 248, 249, 251, 252, 253, 255, 256, 257, 259, 260, 262, 263, 264, 266,
		 267, 269, 270, 272, 273, 275, 276, 278, 279, 281, 282, 284, 285, 287, 288, 290, 291, 293, 294, 296,
		 297, 299, 300, 302, 303, 305, 306, 308, 309, 311, 312, 314, 315, 317, 318, 320, 321, 323, 324, 326,
		 328, 329, 331, 332, 334, 335, 337, 339, 340, 342, 343, 345, 347, 348, 350, 352, 353, 355, 357, 358,
		 360, 362, 363, 365, 367, 368, 370, 372, 374, 375, 377, 379, 380, 382, 384, 386, 387, 389, 391, 392,
		 394, 396, 398, 399, 401, 403, 404, 406, 408, 409, 411, 412, 413, 415, 416, 417, 419, 420, 421, 422,
		 424, 425, 426, 427, 428, 429, 431, 432, 433, 434, 435, 436, 437, 438, 439, 440, 441, 442, 443, 444,
		 445, 446, 447, 448, 449, 450, 451, 451, 452, 453, 454, 455, 456, 456, 457, 458, 459, 460, 460, 461,
		 462, 463, 463, 464, 465, 465, 466, 467, 467, 468, 469, 469, 470, 471, 471, 472, 472, 473, 474, 474,
		 475, 475, 476, 476, 477, 477, 478, 478, 479, 479, 480, 480, 481, 481, 482, 482, 483, 483, 483, 484,
		 484, 485, 485, 485, 486, 486, 486, 487, 487, 487, 488, 488, 488, 489, 489, 489, 490, 490, 490, 491,
		 491, 491, 491, 492, 492, 492, 492, 493, 493, 493, 493, 494, 494, 494, 494, 494, 495, 495, 495, 495,
		 495, 495, 496, 496, 496, 496, 496, 496, 497, 497, 497, 497, 497, 497, 497, 497, 498, 498, 498, 498,
		 498, 498, 498, 498, 498, 499, 499, 499, 499, 499, 499, 499, 499, 499, 499, 499, 500, 500, 500, 500,
		 500, 500, 500, 500, 500, 500, 500, 500, 501, 501, 501, 501, 501, 501, 501, 501, 501, 501, 502, 502,
		 502, 502, 502, 502, 502, 502, 502, 503, 503, 503, 503, 503, 503, 503, 504, 504, 504, 504, 504, 504,
		 504, 505, 505, 505, 505, 505, 506, 506, 506, 506, 506, 507, 507, 507, 507, 508, 508, 508, 509, 509,
		 509, 509, 510, 510, 510, 511, 511, 511, 512, 512, 512, 513, 513, 513, 514, 514, 515, 515, 515, 516,
		 516, 517, 517, 518, 518, 518, 519, 519, 520, 520, 521, 521, 522, 523, 523, 524, 524, 525, 525, 526,
		 526, 527, 528, 528, 529, 530, 530, 531, 532, 532, 533, 534, 534, 535, 536, 537, 537, 538, 539, 540,
		 540, 541, 542, 543, 544, 545, 545, 546, 547, 548, 549, 550, 551, 552, 553, 554, 555, 556, 557, 558,
		 559, 560, 561, 562, 563, 564, 565, 566, 567, 568, 570, 571, 572, 573, 574, 576, 577, 578, 579, 581,
		 582, 583, 585, 586, 587, 589, 590, 591, 593, 594, 596, 598, 599, 601, 603, 605, 606, 608, 610, 611,
		 613, 615, 617, 618, 620, 622, 624, 625, 627, 629, 630, 632, 634, 636, 637, 639, 641, 642, 644, 646,
		 647, 649, 651, 652, 654, 656, 657, 659, 661, 662, 664, 666, 667, 669, 670, 672, 674, 675, 677, 678,
		 680, 681, 683, 685, 686, 688, 689, 691, 692, 694, 695, 697, 698, 700, 701, 703, 705, 706, 708, 709,
		 711, 712, 714, 715, 717, 718, 720, 721, 723, 725, 726, 728, 729, 731, 732, 734, 735, 737, 738, 740,
		 741, 742, 744, 745, 747, 748, 749, 751, 752, 754, 755, 756, 758, 759, 760, 761, 763, 764, 765, 766,
		 767, 768, 770, 771, 772, 773, 774, 775, 776, 777, 778, 779, 780, 781, 782, 783, 783, 784, 785, 786,
		 787, 788, 788, 789, 790, 791, 791, 792, 793, 794, 794, 795, 796, 797, 797, 798, 799, 800, 800, 801,
		 802, 803, 803, 804, 805, 806, 806, 807, 808, 808, 809, 810, 811, 811, 812, 813, 814, 814, 815, 816,
		 816, 817, 818, 818, 819, 820, 821, 821, 822, 823, 823, 824, 825, 826, 826, 827, 828, 828, 829, 830,
		 830, 831, 832, 833, 833, 834, 835, 835, 836, 837, 837, 838, 839, 839, 840, 841, 841, 842, 843, 843,
		 844, 845, 845, 846, 847, 847, 848, 849, 849, 850, 850, 851, 852, 852, 853, 854, 854, 855, 855, 856,
		 857, 857, 858, 858, 859, 859, 860, 861, 861, 862, 862, 863, 863, 864, 865, 865, 866, 866, 867, 867,
		 868, 868, 869, 869, 870, 870, 871, 871, 872, 872, 873, 873, 874, 874, 875, 875, 875, 876, 876, 877,
		 877, 878, 878, 878, 879, 879, 879, 880, 880, 881, 881, 881, 882, 882, 882, 883, 883, 883, 884, 884,
		 884, 884, 885, 885, 885, 886, 886, 886, 886, 887, 887, 887, 887, 887, 888, 888, 888, 888, 888, 889,
		 889, 889, 889, 889, 890, 890, 890, 890, 890, 890, 890, 891, 891, 891, 891, 891, 891, 891, 892, 892
};


short motor_izquierdo[1001]={		
		 392,
		 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392,
		 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392,
		 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392,
		 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392,
		 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392,
		 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392,
		 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392,
		 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392,
		 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392,
		 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392, 392,
		 392, 392, 392, 392, 392, 393, 393, 394, 394, 395, 395, 396, 397, 398, 398, 399, 400, 402, 403, 404,
		 405, 406, 408, 409, 411, 412, 414, 415, 417, 418, 420, 422, 424, 426, 428, 429, 431, 433, 435, 437,
		 440, 442, 444, 446, 448, 450, 453, 455, 457, 459, 462, 464, 466, 469, 471, 473, 476, 478, 481, 483,
		 485, 488, 490, 493, 495, 497, 500, 502, 505, 507, 510, 512, 514, 517, 519, 522, 524, 526, 529, 531,
		 534, 536, 538, 541, 543, 546, 548, 550, 553, 555, 558, 560, 562, 565, 567, 569, 572, 574, 576, 579,
		 581, 583, 586, 588, 590, 593, 595, 597, 599, 602, 604, 606, 609, 611, 613, 615, 617, 620, 622, 624,
		 626, 629, 631, 633, 635, 637, 639, 641, 644, 646, 648, 650, 651, 653, 655, 657, 659, 661, 663, 665,
		 666, 668, 670, 672, 673, 675, 677, 678, 680, 682, 683, 685, 686, 688, 689, 691, 692, 694, 695, 697,
		 698, 700, 701, 703, 704, 705, 707, 708, 709, 711, 712, 713, 715, 716, 717, 718, 720, 721, 722, 723,
		 724, 726, 727, 728, 729, 730, 731, 732, 733, 735, 736, 737, 738, 739, 740, 741, 742, 742, 743, 744,
		 745, 746, 747, 748, 749, 749, 750, 751, 752, 753, 753, 754, 755, 755, 756, 757, 757, 758, 759, 759,
		 760, 761, 761, 762, 762, 763, 763, 764, 764, 765, 765, 766, 766, 767, 767, 768, 768, 768, 769, 769,
		 769, 770, 770, 770, 771, 771, 771, 772, 772, 772, 773, 773, 773, 773, 774, 774, 774, 774, 774, 775,
		 775, 775, 775, 775, 776, 776, 776, 776, 776, 777, 777, 777, 777, 777, 777, 777, 778, 778, 778, 778,
		 778, 778, 778, 778, 779, 779, 779, 779, 779, 779, 779, 779, 779, 779, 779, 779, 780, 780, 780, 780,
		 780, 780, 780, 780, 780, 780, 780, 780, 780, 780, 780, 780, 780, 780, 780, 780, 780, 780, 780, 780,
		 780, 780, 780, 780, 780, 780, 780, 779, 779, 779, 779, 779, 779, 779, 779, 779, 779, 779, 779, 779,
		 779, 779, 779, 778, 778, 778, 778, 778, 778, 778, 778, 778, 778, 778, 777, 777, 777, 777, 777, 777,
		 777, 776, 776, 776, 776, 776, 775, 775, 775, 775, 775, 774, 774, 774, 774, 773, 773, 773, 773, 772,
		 772, 772, 772, 771, 771, 771, 770, 770, 770, 769, 769, 769, 768, 768, 767, 767, 767, 766, 766, 765,
		 765, 764, 764, 764, 763, 763, 762, 762, 761, 761, 760, 760, 759, 758, 758, 757, 757, 756, 756, 755,
		 754, 754, 753, 752, 752, 751, 750, 750, 749, 748, 748, 747, 746, 745, 744, 744, 743, 742, 741, 740,
		 740, 739, 738, 737, 736, 735, 734, 733, 732, 731, 730, 729, 728, 727, 726, 725, 724, 723, 722, 721,
		 720, 718, 717, 716, 715, 713, 712, 711, 710, 708, 707, 705, 703, 702, 700, 698, 697, 695, 693, 692,
		 690, 688, 687, 685, 683, 681, 680, 678, 676, 674, 673, 671, 669, 667, 665, 664, 662, 660, 658, 657,
		 655, 653, 651, 649, 648, 646, 644, 642, 641, 639, 637, 635, 634, 632, 630, 628, 627, 625, 623, 621,
		 620, 618, 616, 614, 613, 611, 609, 608, 606, 604, 603, 601, 599, 598, 596, 594, 593, 591, 589, 588,
		 586, 585, 583, 582, 580, 579, 577, 576, 574, 573, 571, 570, 568, 567, 566, 564, 563, 562, 560, 559,
		 558, 557, 555, 554, 553, 552, 551, 550, 549, 548, 547, 546, 545, 544, 543, 542, 542, 541, 540, 540,
		 539, 538, 538, 537, 537, 536, 536, 535, 535, 535, 534, 534, 534, 534, 533, 533, 533, 533, 533, 533,
		 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533,
		 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533,
		 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533,
		 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533,
		 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533,
		 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533,
		 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533,
		 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533,
		 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533,
		 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533
};


short motor_derecho[1001]={		
		533,
		 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533,
		 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533,
		 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533,
		 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533,
		 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533,
		 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533,
		 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533,
		 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533,
		 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533,
		 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533, 533,
		 533, 533, 533, 533, 533, 533, 534, 534, 534, 534, 535, 535, 535, 536, 536, 537, 537, 538, 538, 539,
		 540, 540, 541, 542, 542, 543, 544, 545, 546, 547, 548, 549, 550, 551, 552, 553, 554, 555, 556, 557,
		 559, 560, 561, 562, 564, 565, 566, 567, 569, 570, 572, 573, 574, 576, 577, 579, 580, 582, 583, 585,
		 586, 588, 590, 591, 593, 594, 596, 598, 599, 601, 603, 604, 606, 608, 609, 611, 613, 614, 616, 618,
		 620, 621, 623, 625, 626, 628, 630, 632, 634, 635, 637, 639, 641, 642, 644, 646, 648, 650, 651, 653,
		 655, 657, 659, 660, 662, 664, 666, 668, 669, 671, 673, 675, 676, 678, 680, 682, 684, 685, 687, 689,
		 691, 692, 694, 696, 697, 699, 701, 702, 704, 706, 707, 708, 710, 711, 712, 713, 715, 716, 717, 718,
		 719, 720, 722, 723, 724, 725, 726, 727, 728, 729, 730, 731, 732, 733, 734, 735, 736, 736, 737, 738,
		 739, 740, 741, 742, 742, 743, 744, 745, 745, 746, 747, 748, 748, 749, 750, 750, 751, 752, 752, 753,
		 754, 754, 755, 756, 756, 757, 757, 758, 758, 759, 759, 760, 760, 761, 761, 762, 762, 763, 763, 764,
		 764, 765, 765, 766, 766, 766, 767, 767, 768, 768, 768, 769, 769, 769, 770, 770, 770, 771, 771, 771,
		 772, 772, 772, 772, 773, 773, 773, 773, 774, 774, 774, 774, 775, 775, 775, 775, 775, 776, 776, 776,
		 776, 776, 776, 777, 777, 777, 777, 777, 777, 777, 777, 778, 778, 778, 778, 778, 778, 778, 778, 778,
		 778, 778, 779, 779, 779, 779, 779, 779, 779, 779, 779, 779, 779, 779, 779, 779, 779, 779, 779, 780,
		 780, 780, 780, 780, 780, 780, 780, 780, 780, 780, 780, 780, 780, 780, 780, 780, 780, 780, 780, 780,
		 780, 780, 780, 780, 780, 780, 780, 780, 779, 779, 779, 779, 779, 779, 779, 779, 779, 779, 778, 778,
		 778, 778, 778, 778, 778, 778, 777, 777, 777, 777, 777, 777, 777, 776, 776, 776, 776, 776, 775, 775,
		 775, 775, 775, 774, 774, 774, 774, 773, 773, 773, 773, 772, 772, 772, 771, 771, 771, 771, 770, 770,
		 769, 769, 769, 768, 768, 767, 767, 766, 766, 766, 765, 765, 764, 763, 763, 762, 762, 761, 761, 760,
		 759, 759, 758, 757, 757, 756, 755, 755, 754, 753, 752, 752, 751, 750, 749, 748, 747, 747, 746, 745,
		 744, 743, 742, 741, 740, 739, 738, 737, 736, 735, 734, 733, 731, 730, 729, 728, 727, 726, 724, 723,
		 722, 721, 719, 718, 717, 716, 714, 713, 712, 710, 709, 708, 706, 705, 703, 702, 700, 699, 698, 696,
		 695, 693, 691, 690, 688, 687, 685, 684, 682, 680, 679, 677, 675, 674, 672, 670, 668, 667, 665, 663,
		 661, 659, 657, 656, 654, 652, 650, 648, 646, 644, 642, 640, 637, 635, 633, 631, 629, 626, 624, 622,
		 620, 618, 615, 613, 611, 609, 606, 604, 602, 599, 597, 595, 593, 590, 588, 586, 583, 581, 579, 576,
		 574, 572, 569, 567, 565, 562, 560, 558, 555, 553, 551, 548, 546, 543, 541, 539, 536, 534, 532, 529,
		 527, 524, 522, 520, 517, 515, 512, 510, 507, 505, 503, 500, 498, 495, 493, 491, 488, 486, 483, 481,
		 478, 476, 474, 471, 469, 467, 464, 462, 460, 457, 455, 453, 450, 448, 446, 444, 442, 439, 437, 435,
		 433, 431, 429, 427, 425, 423, 421, 420, 418, 416, 414, 413, 411, 410, 408, 407, 405, 404, 403, 401,
		 400, 399, 398, 397, 396, 395, 394, 393, 393, 392, 391, 391, 390, 390, 390, 389, 389, 389, 389, 389,
		 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389,
		 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389,
		 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389,
		 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389,
		 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389,
		 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389,
		 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389,
		 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389,
		 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389,
		 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389, 389
};