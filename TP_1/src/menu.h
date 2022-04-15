/* menu.h
 *
 *	Created on: 9 abr. 2022
 *      Author: Morena Fernandez
 */

#include <stdio.h>
#include <stdlib.h>
#ifndef MENU_H_
#define MENU_H_

/**
 * @fn int menu()
 * @brief Muestra un menu con opciones, pide que se elija una opcion y retorna esa opcion
 *
 * @return opcion
 */
int menu(float kilometros, float precioLatam,float precioAero);

/**
 * @fn float pedirKm()
 * @brief Pide los kilometros y los retorna
 *
 * @return kilometros
 */
float pedirKm();

/**
 * @fn float pedirPrecioLatam()
 * @brief Pide el precio del vuelo para Latam y lo retorna
 *
 * @return precioLatam
 */
float pedirPrecioLatam();

/**
 * @fn float pedirPrecioAero()
 * @brief Pide el precio del vuelo para Aerolineas Arg y lo retorna
 *
 * @return precioAero
 */
float pedirPrecioAero();

/**
 * @fn float calcularLatam(float, float, int)
 * @brief Realiza los costos del vuelo para Latam, segun la opcion (a), retorna un valor distinto
 *
 * @param precioLatam
 * @param km
 * @param a
 * @return valorRetornar
 */
float calcularLatam(float precioLatam,float km, int a);

/**
 * @fn float calcularAero(float, float, int)
 * @brief Realiza los costos del vuelo de Aerolineas, segun la opcion (b), retorna un valor distinto
 *
 * @param precioAero
 * @param km
 * @param b
 * @return valorRetornar
 */
float calcularAero(float precioAero, float km, int b);

/**
 * @fn float diferenciaLatamAero(float, float)
 * @brief Realiza la diferencia entre el precio de Latam y el de Aerolineas, en caso de que sea negativo se multiplica para que quede positivo
 *
 * @param precioLatam
 * @param precioAero
 * @return diferencia
 */
float diferenciaLatamAero(float precioLatam, float precioAero);

/**
 * @fn void mostrar(float, float, float, float, float, float, float, float, float, float, float)
 * @brief Muestra los datos ya ingresados y calculados, no retorna nada
 *
 * @param precioLatam
 * @param precioAero
 * @param debitoLat
 * @param creditoLat
 * @param bitcoinLat
 * @param precioUnitarioLat
 * @param debitoAero
 * @param creditoAero
 * @param bitcoinAero
 * @param precioUnitarioAero
 * @param diferencia
 */
void mostrar(float precioLatam, float precioAero, float debitoLat, float creditoLat, float bitcoinLat, float precioUnitarioLat, float debitoAero, float creditoAero, float bitcoinAero,  float precioUnitarioAero, float diferencia);


#endif /* MENU_H_ */
