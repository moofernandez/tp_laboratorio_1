/*
 * menu.c
 *
 *  Created on: 9 abr. 2022
 *      Author: Morena Fernandez
 */

#include <stdio.h>
#include <stdlib.h>

int menu(float kilometros, float precioLatam,float precioAero){

	int opcion;

	printf("\n\n ----------Menu de opciones----------\n");
	printf("\n 1. Ingresar Kilometros. km = %f ",kilometros);
	printf("\n 2. Ingresar Precio de Vuelos. Aerolineas = %f y Latam = %f ", precioLatam, precioAero);
	printf("\n 3. Calcular todos los costos. ");
	printf("\n 4. Informar Resultados. ");
	printf("\n 5. Carga forzada de datos. ");
	printf("\n 6. Salir. \n");

	printf("\n Elija una opcion: ");
	scanf("%d", &opcion);

	return opcion;

	printf("\n\n ------------------------------------\n");
}

float pedirKm(){

	float kilometros;

		printf("\n Ingrese los km del vuelo: ");
		scanf("%f",&kilometros);

			while (kilometros <= 0){
				printf("Incorrecto. Ingrese los km del vuelo: ");
				scanf("%f",&kilometros);
			}

	return kilometros;
}

float pedirPrecioLatam(){

	float precioLatam;

		printf ("\n Ingrese el precio del vuelo de Latam: ");
		scanf("%f",&precioLatam);

			while(precioLatam <= 0){
				printf ("Ingrese el precio del vuelo de Latam: ");
				scanf("%f",&precioLatam);
			}

	return precioLatam;
}

float pedirPrecioAero(){

	float precioAero;

		printf("\n Ingrese el precio del vuelo de Aerolineas Arg: ");
		scanf("%f",&precioAero);

		while(precioAero <= 0){
			printf("Ingrese el precio del vuelo de Aerolineas Arg: ");
			scanf("%f",&precioAero);
	}

	return precioAero;
}

float calcularLatam(float precioLatam,float km, int a){

	float debitoLat; // -%10
	float creditoLat; // +%25
	float bitcoinLat;
	float precioUnitarioLat;
	float valorRetornar;

	switch(a){
		case 1:
			debitoLat = precioLatam - (precioLatam * 10 / 100); // calculo precio x debito
			valorRetornar = debitoLat;
			break;

		case 2:
			creditoLat = precioLatam + (precioLatam * 25 / 100); //calculo precio x credito
			valorRetornar = creditoLat;
			break;

		case 3:
			bitcoinLat= 4606954.55 / (precioLatam * 100); // calculo precio x bitcoin
			valorRetornar = bitcoinLat;
			break;

		case 4:
			precioUnitarioLat = precioLatam * km; // precio por km
			valorRetornar = precioUnitarioLat;
			break;
	}
	return valorRetornar ;
}

float calcularAero(float precioAero, float km, int b){

	float debitoAero; // -%10
	float creditoAero; // +%25
	float bitcoinAero; // (1BTC -> 4606954.55 Pesos Argentinos)
    float precioUnitarioAero;
    float valorRetornar;

	switch(b){
		case 1:
			debitoAero = precioAero - (precioAero * 10 / 100); // calculo precio x debito
			valorRetornar = debitoAero;
			break;
		case 2:
			creditoAero = precioAero + (precioAero *25 / 100); //calculo precio x credito
			valorRetornar = creditoAero;
			break;
		case 3:
			bitcoinAero = 4606954.55 / (precioAero * 100); // calculo precio x bitcoin
			valorRetornar = bitcoinAero;
			break;
		case 4:
			precioUnitarioAero = precioAero * km; // precio por km
			valorRetornar = precioUnitarioAero;
			break;
		}
	return valorRetornar;
}

float diferenciaLatamAero(float precioLatam, float precioAero){

	float diferencia;

	diferencia = precioLatam - precioAero; // calculo la diferencia (si es negativa la multplica por -1 para que quede positiva)

	if (diferencia < 0 ){
		diferencia *= -1 ;
	}

	return diferencia;
}

void mostrar(float precioLatam, float precioAero,float debitoLat, float creditoLat, float bitcoinLat, float precioUnitarioLat, float debitoAero, float creditoAero, float bitcoinAero,  float precioUnitarioAero, float diferencia){

	// imprimir por consola todos los datos ingresados y calculados

	printf ("\n Latam:  $ %2.f ", precioLatam);
	printf ("\n a) Precio con tarjeta de debito: $ %f ",debitoLat);
	printf ("\n b) Precio con tarjeta de credito: $ %f ",creditoLat);
	printf ("\n c) Precio pagando con bitcoin: $ %f ",bitcoinLat);
	printf ("\n d) Precio unitario: %2.f  ",precioUnitarioLat);

	printf ("\n \n Aerolineas Argentinas: $ %f ", precioAero);
	printf ("\n a) Precio con tarjeta de debito: $ %f ",debitoAero);
	printf ("\n b) Precio con tarjeta de credito: $ %f ",creditoAero);
	printf ("\n c) Precio pagando con bitcoin: $ %f ",bitcoinAero);
	printf ("\n d) Precio unitario: $ %2.f ",precioUnitarioAero);

	printf("\n La diferencia de precio es de $ %f ",diferencia);

}
