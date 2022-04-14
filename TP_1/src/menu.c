/*
 * menu.c
 *
 *  Created on: 9 abr. 2022
 *      Author: Morena Fernandez
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

/**
 * @fn int menu()
 * @brief Muestra un menu con opciones, pide que se elija una opcion y retorna esa opcion
 *
 * @return opcion
 */
int menu(){

	int opcion;

	printf("\n\n ----------Menu de opciones----------\n");
	printf("\n 1. Ingresar Kilometros: ");
	printf("\n 2. Ingresar Precio de Vuelos(Aerolineas y Latam)");
	printf("\n 3. Calcular todos los costos");
	printf("\n 4. Informar Resultados");
	printf("\n 5. Carga forzada de datos");
	printf("\n 6. Salir \n");

	printf("\n Elija una opcion: ");
	scanf("%d", &opcion);

	return opcion;
}

/**
 * @fn float pedirKm()
 * @brief Pide los kilometros y los retorna
 *
 * @return kilometros
 */
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

/**
 * @fn float pedirPrecioLatam()
 * @brief Pide el precio del vuelo para Latam y lo retorna
 *
 * @return precioLatam
 */
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

/**
 * @fn float pedirPrecioAero()
 * @brief Pide el precio del vuelo para Aerolineas Arg y lo retorna
 *
 * @return precioAero
 */
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

/**
 * @fn float calcularLatam(float, float, int)
 * @brief Realiza los costos del vuelo para Latam, segun la opcion (a), retorna un valor distinto
 *
 * @param precioLatam
 * @param km
 * @param a
 * @return valorRetornar
 */
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

/**
 * @fn float calcularAero(float, float, int)
 * @brief Realiza los costos del vuelo de Aerolineas, segun la opcion (b), retorna un valor distinto
 *
 * @param precioAero
 * @param km
 * @param b
 * @return valorRetornar
 */
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
void mostrar(float precioLatam, float precioAero,float debitoLat, float creditoLat, float bitcoinLat, float precioUnitarioLat, float debitoAero, float creditoAero, float bitcoinAero,  float precioUnitarioAero, float diferencia){

	// imprimir por consola todos los datos ingresados y calculados

	printf ("\n Latam:  $ %f ", precioLatam);
	printf ("\n a) Precio con tarjeta de debito: $ %f ",debitoLat);
	printf ("\n b) Precio con tarjeta de credito: $ %f ",creditoLat);
	printf ("\n c) Precio pagando con bitcoin: $ %f ",bitcoinLat);
	printf ("\n d) Precio unitario: %f ",precioUnitarioLat);

	printf ("\n \n Aerolineas Argentinas: $ %f ", precioAero);
	printf ("\n a) Precio con tarjeta de debito: $ %f ",debitoAero);
	printf ("\n b) Precio con tarjeta de credito: $ %f ",creditoAero);
	printf ("\n c) Precio pagando con bitcoin: $ %f ",bitcoinAero);
	printf ("\n d) Precio unitario: $ %f ",precioUnitarioAero);

	printf("\n La diferencia de precio es de $ %f ",diferencia);

}

/**
 * @fn float diferenciaLatamAero(float, float)
 * @brief Realiza la diferencia entre el precio de Latam y el de Aerolineas, en caso de que sea negativo se multiplica para que quede positivo
 *
 * @param precioLatam
 * @param precioAero
 * @return diferencia
 */
float diferenciaLatamAero(float precioLatam, float precioAero){ // calculo la diferencia (si es negativa la multplica por -1 para que quede positiva)

	float diferencia;

	diferencia = precioLatam - precioAero;

	if (diferencia < 0 ){
		diferencia *= -1 ;
	}

	return diferencia;
}
