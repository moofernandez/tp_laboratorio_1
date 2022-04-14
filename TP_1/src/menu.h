/* menu.h
 *
 *	Created on: 9 abr. 2022
 *      Author: Morena Fernandez
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#ifndef MENU_H_
#define MENU_H_

int menu();
float pedirKm();
float pedirPrecioLatam();
float pedirPrecioAero();
float calcularLatam(float precioLatam,float km, int a);
float calcularAero(float precioAero, float km, int b);
float diferenciaLatamAero(float precioLatam, float precioAero);
void mostrar(float precioLatam, float precioAero, float debitoLat, float creditoLat, float bitcoinLat, float precioUnitarioLat, float debitoAero, float creditoAero, float bitcoinAero,  float precioUnitarioAero, float diferencia);


#endif /* MENU_H_ */
