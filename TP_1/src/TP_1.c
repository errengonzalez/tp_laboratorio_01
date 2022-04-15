/*
 ============================================================================
 Name        : TP_1.c
 Author      : rodrigo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca_calculos.h"

int main(void) {
	setbuf(stdout, NULL);
	int opcion;

	int pkmsIngresados;
	int pPrecioAerolineas;
	int pPrecioLatam;

	float pPrecioTarjetaDebitoAerolineas;
	float pPrecioTarjetaCreditoAerolineas;
	double pPrecioBtcAerolineas;
	double pPrecioUnitarioAerolineas;

	float pPrecioTarjetaDebitoLatam;
	float pPrecioTarjetaCreditoLatam;
	double pPrecioBtcLatam;
	double pPrecioUnitarioLatam;
	float pDiferenciaPrecio;

	float pHardPrecioTarjetaDebitoAerolineas;
	float pHardPrecioTarjetaCreditoAerolineas;
	double pHardPrecioBtcAerolineas;
	double pHardPrecioUnitarioAerolineas;

	float pHardPrecioTarjetaDebitoLatam;
	float pHardPrecioTarjetaCreditoLatam;
	double pHardPrecioBtcLatam;
	double pHardPrecioUnitarioLatam;
	float pHardDiferenciaPrecio;

do{
	menu();
	scanf("%d", &opcion);

		switch(opcion)
		{
			case 1:
				utn_getNumeroEntero(&pkmsIngresados, "Ingrese Kilometros: \n","No es un dato valido, vuelva a ingresar\n", 0, 2000000,2);
				printf("\nPresione 2 Para Continuar... ");
				break;
			case 2:
				utn_getNumeroEntero(&pPrecioAerolineas, "Ingrese Precio de Aerolineas: \n","No es un dato valido, vuelva a ingresar\n", 0, 2000000,2);
				utn_getNumeroEntero(&pPrecioLatam, "Ingrese Precio de Latam: \n","No es un dato valido, vuelva a ingresar\n", 0, 2000000,2);
				printf("\nPresione 3 Para Continuar... \n");
				break;
			case 3:
				menuInformativo();
				//CALCULOS AEROLINEAS
				calculoTarjetaDebito(&pPrecioTarjetaDebitoAerolineas, pPrecioAerolineas);//A
				calculoTarjetaCredito(&pPrecioTarjetaCreditoAerolineas, pPrecioAerolineas);//B
				calculoPrecioBtc(&pPrecioBtcAerolineas, pPrecioAerolineas);//C
				dividir(&pPrecioUnitarioAerolineas,pPrecioAerolineas,  pkmsIngresados);//D

				//CALCULOS LATAM
				calculoTarjetaDebito(&pPrecioTarjetaDebitoLatam, pPrecioLatam);//A
				calculoTarjetaCredito(&pPrecioTarjetaCreditoLatam, pPrecioLatam);//B
				calculoPrecioBtc(&pPrecioBtcLatam, pPrecioLatam);//C
				dividir(&pPrecioUnitarioLatam, pPrecioLatam, pkmsIngresados);//D
				diferencia(&pDiferenciaPrecio, pPrecioAerolineas, pPrecioLatam);
				printf("\nPresione 4 Para Continuar...\n ");
				break;
			case 4:
				printf("-----------------OPERACIONES CARGA FORZADA--------------\n \n" );
				printf("KMs Ingresados: %d km\n\n", pkmsIngresados);
				printf("\nPrecio Aerolineas: $ %d \n",pPrecioAerolineas);
				printf(" a) Precio con Tarjeta de Debito: $ %.2f\n", pPrecioTarjetaDebitoAerolineas);
				printf(" b) Precio con Tarjeta de Credito: $ %.2f\n", pPrecioTarjetaCreditoAerolineas);
				printf(" c) Precio Pagando con Bitcoin:  %.5f BTC\n", pPrecioBtcAerolineas);
				printf(" d) Mostrar Precio Unitario: $ %.2f\n", pPrecioUnitarioAerolineas);
				printf("\nPrecio Latam: $ %d \n", pPrecioLatam);
				printf(" a) Precio con Tarjeta de Debito: $ %.2f\n", pPrecioTarjetaDebitoLatam);
				printf(" b) Precio con Tarjeta de Credito: $ %.2f\n", pPrecioTarjetaCreditoLatam);
				printf(" c) Precio Pagando con Bitcoin:  %.4f BTC\n", pPrecioBtcLatam);
				printf(" d) Mostrar Precio Unitario: $ %.2f\n\n", pPrecioUnitarioLatam);
				printf("\n La diferencia de precio es:  $ %.2f\n", pDiferenciaPrecio);
				printf("\n Presione 5 para la carga forzada de datos:\n");
				break;
			case 5:
				//CALCULOS AEROLINEAS
				calculoTarjetaDebito(&pHardPrecioTarjetaDebitoAerolineas, AEROLINEASHARD);//A
				calculoTarjetaCredito(&pHardPrecioTarjetaCreditoAerolineas, AEROLINEASHARD);//B
				calculoPrecioBtc(&pHardPrecioBtcAerolineas, AEROLINEASHARD);//C
				dividir(&pHardPrecioUnitarioAerolineas,AEROLINEASHARD,  KMHARD);//D

				//CALCULOS LATAM
				calculoTarjetaDebito(&pHardPrecioTarjetaDebitoLatam, LATAMHARD);//A
				calculoTarjetaCredito(&pHardPrecioTarjetaCreditoLatam, LATAMHARD);//B
				calculoPrecioBtc(&pHardPrecioBtcLatam, LATAMHARD);//C
				dividir(&pHardPrecioUnitarioLatam, LATAMHARD, KMHARD);//D
				diferencia(&pHardDiferenciaPrecio, AEROLINEASHARD, LATAMHARD);

				printf("-----------------RESULTADOS DE SU CARGA DE DATOS--------------\n \n" );
				printf("KMs Ingresados: %d km\n\n", KMHARD);
				printf("\nPrecio Aerolineas: $ %d \n",AEROLINEASHARD);
				printf(" a) Precio con Tarjeta de Debito: $ %.2f\n", pHardPrecioTarjetaDebitoAerolineas);
				printf(" b) Precio con Tarjeta de Credito: $ %.2f\n", pHardPrecioTarjetaCreditoAerolineas);
				printf(" c) Precio Pagando con Bitcoin:  %.5f BTC\n", pHardPrecioBtcAerolineas);
				printf(" d) Mostrar Precio Unitario: $ %.2f\n", pHardPrecioUnitarioAerolineas);
				printf("\nPrecio Latam: $ %d \n", LATAMHARD);
				printf(" a) Precio con Tarjeta de Debito: $ %.2f\n", pHardPrecioTarjetaDebitoLatam);
				printf(" b) Precio con Tarjeta de Credito: $ %.2f\n", pHardPrecioTarjetaCreditoLatam);
				printf(" c) Precio Pagando con Bitcoin:  %.4f BTC\n", pHardPrecioBtcLatam);
				printf(" d) Mostrar Precio Unitario: $ %.2f\n\n", pHardPrecioUnitarioLatam);
				printf("\n La diferencia de precio es:  $ %.2f\n", pHardDiferenciaPrecio);
				printf("\n Presione 6 Para Salir:\n");

				break;
				case 6:
				break;
				default:
				printf("ERROR dato no valido, vuelva a ingresar");
		}
}while (opcion != 6);

	return 0;
}


