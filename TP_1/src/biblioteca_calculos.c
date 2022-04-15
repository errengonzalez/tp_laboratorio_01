/*
 * biblioteca_calculos.c
 *
 *  Created on: 14 abr. 2022
 *      Author: RODRIGO NELSON GONZALEZ
 *		BIBLIOTECA DE OPERACIONES DE PRECIOS INGRESADOS
 *		TP_1
 */
#include <stdio.h>
#include <stdlib.h>
#include "biblioteca_calculos.h"
/**
 *MENU INFORMATIVO
 */
void menu(void)
{
	printf("\n\n-----------------MENU PRINCIPAL-------------------- \n" );
	printf("1- Ingresar Kilometros: (KM= )\n" );
	printf("2- Ingresar Precio de Vuelos: (Aerolineas / Latam)\n");
	printf("3- Calcular Todos Los Costos:\n");
	printf("4- Informar Resultados\n");
	printf("5- Carga Forzada:\n");
	printf("6- Salir:\n");
}
/**
 *ESTA FUNCION PIDE UN NUMERO ENTERO DANDOLE UN RANGO DE MAXIMO Y MINIMO Y UNA VALIDACION EN CASO QUE HAYA INGRESADO MAL EL DATO, Y TIENE REINTENTOS
 * @param pResultado, ESTE PUNTERO GUARDA LA SOLUCION, EN CASO QUE LA VALIDACION RESULTE CORRECTA
 * @param MENSAJE EN DONDE SE LE PIDE AL USUARIO QUE INGRESE UN NUMERO
 * @param mensajeError EN CASO QUE HAYA INGRESADO UN DATO INVALIDO
 * @param MINIMO RANGO MINIMO PERMITIDO PARA EL INGRESO
 * @param MAXIMO MAXIMO DE NUMERO INGRESADO
 * @param REINTENTOS CANTIDAD DE VECES PARA VOLVER A PREGUNTAR
 * @return RETORNA 0 O 1 Y CUANDO RETORNA 0 REALIZA LA FUNCION
 */
int utn_getNumeroEntero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int bufferInt;
	int retorno = -1;

		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
		{
			do
			{
				printf("%s", mensaje);
				scanf("%d", &bufferInt);

				if(bufferInt >=minimo && bufferInt <= maximo)
				{
					*pResultado = bufferInt;
					retorno = 0;
					break;
				}
				else
				{
					printf("%s",mensajeError);
					reintentos--;
				}
			 }while(reintentos >= 0);
		}
			return retorno;
}

/**
 *SUBMENU INFORMATIVO
 */
void menuInformativo(void)
{
	printf("\n-------- SE CALCULARAN LOS SIGUIENTES DATOS-----------\n");
	printf(" a) Tarjeta de debito descuento 10 (PORCIENTO)\n");
	printf(" b) Tarjeta de credito interes 25 (PORCIENTO)\n");
	printf(" c) Bitcoin (1 BTC -> 4606954.55 Pesos Argentinos)\n");
	printf(" d) Mostrar precio por km (precio Unitario)\n");
	printf(" e) Mostrar diferencia de precio ingresada (Latam - Aerolineas)\n\n");
}
/**
 *ESTA FUNCION CALCULA EL DESCUENTO CON TARJETA DE DEBITO, PIDIENDO PRECIO INGRESADO VALIDADO PREVIAMENTE Y REALIZA EL PORCENTAJE DE DESCUENTO
 * @param pResultado VARIABLE ASIGNADA DONDE SE GUARDA EL VALOR EN CASO DE INGRESO VALIDO
 * @param operando1 ES EL PRECIO INGRESADO POR EL USUARIO
 * @return RETORNA 0 EN CASO POSITIVO DE LA OPERACION
 */
float calculoTarjetaDebito(float* pResultado, int operando1)
{
	float resultado;
	int porcentaje = 10;
	float precioFinalConDescuento;
	int retorno = -1;
		if(pResultado != NULL && operando1 > 0)
		{
			resultado = operando1 *porcentaje / 100;
			precioFinalConDescuento=operando1-resultado;
			*pResultado = precioFinalConDescuento;
			retorno = 0;
		}
		return retorno;
}
/**
 *ESTA FUNCION CALCULA EL PRECIO CON INTERES Y DEVUELVE EL RESULTADO VALIDADO PREVIAMENTE
 * @param pResultado VARIABLE DONDE SE VA A GUARDAR EL RESULTADO LUEGO DE LA OPERACION
 * @param operando1 PRECIO INGRESADO POR EL USUARIO
 * @return EN CASO AFIRMATIVO DEVUELVE 0 Y EL RESULTADO DE LA OPERACION
 */
float calculoTarjetaCredito(float* pResultado, int operando1)
{
	float resultado;
	int porcentaje = 25;
	float precioFinalConInteres;
	int retorno = -1;
		if(pResultado != NULL && operando1 > 0)
		{
			resultado = operando1 *porcentaje / 100;
			precioFinalConInteres=operando1+resultado;
			*pResultado = precioFinalConInteres;
			retorno = 0;
		}
		return retorno;
}
/**
 *ESTA FUNCION CALCULA EL PRECIO EN BTC EN BASE AL PRECIO INGRESADO POR EL USUARIO Y GUARDA SU RESULTADO EN SU PUNTERO LUEGO DE VALIDADA LA FUNCION
 * @param pResultado VARIABLE DONDE SE GUARDA EL RESULTADO DE LA OPERACION
 * @param operando1 PRECIO INGRESADO POR EL USUARIO
 * @return EN CASO AFIRMATIVO DEVUELVE 0 Y EL RESULTADO DE LA OPERACION
 */
float calculoPrecioBtc(double* pResultado, int operando1)
{
	double resultado;
	double precioBtc = 4606954.55;
	int retorno = -1;
		if(pResultado != NULL && operando1 > 0)
		{
			resultado = operando1 / precioBtc;
			*pResultado = resultado;
			retorno = 0;
		}
		return retorno;
}

/**
 *FUNCION QUE CALCULA EL PRECIO UNITARIO Y DEVUELVE SU RESULTADO AL PUNTERO EN CASO DE OPERACION VALIDA
 * @param pResultado RESULTADO DE LA OPERACION DE PRECIO UNITARIO
 * @param operando1 PRECIO INGRESADO POR EL USUARIO
 * @param operando2 KILOMETROS INGRESADOS POR EL USUARIO
 * @return EN CASO DE SER VALIDO RETORNA 0 Y REALIZA LA OPERACION
 */
float dividir(double* pResultado, int operando1, int operando2)
{
	double resultado;
	int retorno = -1;
		if(pResultado != NULL && operando2 !=0)
		{
			resultado = (float) operando1 /operando2;
			*pResultado=resultado;
			retorno = 0;
		}
		return retorno;
}
/**
 *FUNCION QUE CALCULA LA DIREFENCIA DE PRECIO ENTRE DOS PRECIOS INGRESADOS
 * @param pResultado RESULTADO DE LA OPERACION DE DIFERENCIA
 * @param operando1 PRECIO INGRESADO POR EL USUARIO
 * @param operando2 PRECIO INGRESADO POR EL USUARIO
 * @return RETORNA 0 EN CASO VALIDO Y REALIZA LA OPERACION DE LA FUNCION
 */
float diferencia(float* pResultado, int operando1, int operando2)
{
	float resultado;
	float retorno = -1;
		if(pResultado != NULL && operando1 > operando2)
		{
			resultado =operando1 - operando2;
			*pResultado= resultado;
			retorno=0;
		}
		else
		{
			resultado =operando2 - operando1;
			*pResultado= resultado;
		}
		return retorno;
}



