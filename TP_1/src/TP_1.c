/*Morena Fernandez Div 1J Trabajo Practico I
 * Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolineas Argentinas
para ofrecerlos a sus clientes.
Se debera ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicacion es mostrar las diferentes opciones de pagos a sus clientes.*/

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int main (void){
setbuf(stdout,NULL);

	int opcion;
	float kilometros;
	float precioLatam;
	float debitoLat;
	float creditoLat;
	float bitcoinLat;
	float precioUnitarioLat;
	float precioAero;
	float debitoAero;
	float creditoAero;
	float bitcoinAero;
	float precioUnitarioAero;
	float diferencia;
	int banderaPrimerCaso;
	int banderaSegundoCaso;
	int banderaTercerCaso;

	opcion = 6;
	banderaPrimerCaso = 0;
	banderaSegundoCaso = 0;
	banderaTercerCaso = 0;
	kilometros = 0;
	precioAero = 0;
	precioLatam = 0;

   do{
		opcion = menu(kilometros,precioAero,precioLatam);

		switch (opcion){

		case 1:        // Ingreso de km
			if (banderaPrimerCaso == 0){
				kilometros= pedirKm(); // pedir km a traves de la funcion
				banderaPrimerCaso = 1;
			}
			break;

		case 2:       // Ingreso de precio de los vuelos
			if (banderaSegundoCaso == 0){
				precioLatam = pedirPrecioLatam(); // pedir precio a traves de la funcion
				precioAero =  pedirPrecioAero();
				banderaSegundoCaso = 1;
			}
			break;

		case 3:       // Calcular costos
			if (banderaTercerCaso == 0 && banderaPrimerCaso == 1 && banderaSegundoCaso == 1){ // solo entra cuando las banderas 1 y 2 estan llenas
				printf(" \n ----Por favor espere se estan realizando los calculos de los costos---- \n ");
				printf ("\n \t\t\t\t CARGANDO......\n");

				debitoLat = calcularLatam(precioLatam, kilometros, 1); // calcula el costo de Latam, y segun el numero de (a) retorna un valor distinto
				creditoLat = calcularLatam(precioLatam, kilometros, 2);
				bitcoinLat = calcularLatam(precioLatam, kilometros, 3);
				precioUnitarioLat = calcularLatam(precioLatam, kilometros, 4);

				debitoAero = calcularAero(precioAero, kilometros, 1); // calcula el costo de Aerolineas , y segun el numero de (b) retorna un valor distinto
				creditoAero = calcularAero(precioAero, kilometros, 2);
				bitcoinAero = calcularAero(precioAero, kilometros, 3);
				precioUnitarioAero = calcularAero(precioAero, kilometros, 4);

				diferencia = diferenciaLatamAero(precioLatam, precioAero); // calcula la diferencia entre Latam y Aerolineas

				banderaTercerCaso = 1;
			}else{
				printf("\n Lo sentimos algo salio mal... Intentelo denuevo");
			}
			break;

		case 4: 	  // Mostrar Datos
			if(banderaPrimerCaso == 1 && banderaSegundoCaso == 1 && banderaTercerCaso == 1){ // solo puede ingresar cuando la bandera1, la bandera2 y bandera3 esten llenas
				mostrar(precioLatam, precioAero, debitoLat, creditoLat, bitcoinLat, precioUnitarioLat, debitoAero, creditoAero, bitcoinAero, precioUnitarioAero, diferencia);
			}else {
				printf("\n Lo sentimos algo salio mal... Intentelo denuevo");
			}
			break;

		case 5:      // Carga forzada de datos
			kilometros = 7090;
			precioAero = 162965;
			precioLatam = 159339;

			debitoLat = calcularLatam(precioLatam, kilometros, 1);
			creditoLat = calcularLatam(precioLatam, kilometros, 2);
			bitcoinLat = calcularLatam(precioLatam, kilometros, 3);
			precioUnitarioLat = calcularLatam(precioLatam, kilometros, 4);

			debitoAero = calcularAero(precioAero, kilometros, 1);
			creditoAero = calcularAero(precioAero, kilometros, 2);
			bitcoinAero = calcularAero(precioAero, kilometros, 3);
			precioUnitarioAero = calcularAero(precioAero, kilometros, 4);

			diferencia = diferenciaLatamAero(precioLatam, precioAero);

			mostrar(precioLatam, precioAero, debitoLat, creditoLat, bitcoinLat,precioUnitarioLat, debitoAero, creditoAero, bitcoinAero, precioUnitarioAero, diferencia);
			break;
		}
     }while(opcion != 6);

	return 0;
}
