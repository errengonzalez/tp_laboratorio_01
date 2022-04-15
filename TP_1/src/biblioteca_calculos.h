/*
 * biblioteca_calculos.h
 *
 *  Created on: 14 abr. 2022
 *      Author: rodri
 */
#ifndef BIBLIOTECA_CALCULOS_H_
#define BIBLIOTECA_CALCULOS_H_
#include <stdio.h>
#include <stdlib.h>

void menu();
int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos);
int utn_getNumeroEntero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
void menuInformativo();
float calculoTarjetaDebito(float* pResultado, int operando1);
float calculoTarjetaCredito(float* pResultado, int operando1);
float calculoPrecioBtc(double* pResultado, int operando1);
float dividir(double* pResultado, int operando1, int operando2);
float diferencia(float* pResultado, int operando1, int operando2);
#define KMHARD 7090
#define AEROLINEASHARD 162965
#define LATAMHARD 159339

#endif /* BIBLIOTECA_CALCULOS_H_ */
