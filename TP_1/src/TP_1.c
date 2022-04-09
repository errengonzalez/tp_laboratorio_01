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

void menu();


int main(void) {
setbuf(stdout, NULL);

int salir = 0;
int opcion;
int kmIngresados;

do{
	menu();
	scanf("%d", &opcion);

switch (opcion) {
	case 1:
		printf("ingrese kilometros: ");
		scanf("%d",&kmIngresados);

		printf("Ha ingresado: %d", kmIngresados);
		break;
	default:
		printf("Error no es un dato valido: ");
		break;
}




}while(salir !=0);
	//puts("!!!PRIMER TRABAJO 2022 !!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
void menu(){
printf("1- Ingresar kilometros: \n" );
printf("2- Ingresar precio de vuelos:\n");
printf("3- Calcular todos los costos:\n");
printf("4- Informar resultados:\n");
printf("5- Carga forzada de datos:\n");
printf("6- Salir:\n");
}

