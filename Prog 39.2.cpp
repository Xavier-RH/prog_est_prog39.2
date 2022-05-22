/* Autor: Xavier Romero Hernández, Realizado: 18/04/2022 
	Programa que almacena las calificaciones de un alumno y su faltas para un grupo de 10 alumnos
	El programa tendra las siguientes opciones:
		0. Salir
		1. Agregar alumnos
		2. Imprimir
		3. Alumnos Aprobados
		4. Alumnos Reprobados
		5. Promedio del grupo
		6. Porcentaje de alumnos Aprobados
		//Para hacer operaciones con las calificaciones de los alumnos se siguen las siguientes reglas
			Si el numero de faltas es <=6, la calificación es la que esta almacenada en el dato promedio de la estructura
            	Pero si no, la calificación que se toma es 5
	*/
	
#include <stdio.h>
#include <stdlib.h>
#include "milibreria.h"
#define MAX 10


int menu();
void agregar(struct alumno x[]);
void imprimir(struct alumno x[],int tipo, char *a);
void promedio(struct alumno x[]);
void porcentajeaprobados(struct alumno x[]);

struct alumno{
	char nombre[30];
	float promedio;
	int faltas;
};

int n=0;

int main(){
	struct alumno grupo[MAX];
	int opcion, centi=0;
	do{
		opcion=menu();
		switch(opcion) {
			case 0: printf("Adios.....\n");
					break;
			case 1: agregar(grupo);
					centi=1;
					break;
			case 2:	if(centi==1){
						imprimir(grupo,0,"Totales");
					}
					else{
						printf("Primero debes llenar los datos.\n");
					}
					system("PAUSE");
					break;
			case 3: if(centi==1){
						imprimir(grupo,1,"Aprobados");
					}
					else{
						printf("Primero debes llenar los datos.\n");
					}
					system("PAUSE");
					break;
			case 4: if(centi==1){
						imprimir(grupo,2,"Reprobados");
					}
					else{
						printf("Primero debes llenar los datos.\n");
					}
					system("PAUSE");
					break;
			case 5: if(centi==1){
						promedio(grupo);
					}
					else{
						printf("Primero debes llenar los datos.\n");
					}
					system("PAUSE");
					break;
			case 6: if(centi==1){
						porcentajeaprobados(grupo);
					}
					else{
						printf("Primero debes llenar los datos.\n");
					}
					system("PAUSE");
					break;		
			default:printf("Opcion no valida, ingresa otra opcion\n\n");
					break;
		}
	}while(opcion!=0);
	
	return 0;
}

//funciones
//Funcion que muestra el menu, pide una opcion, la valida y la regresa
int menu(){
	int opcion;
	printf("----------Menu Principal----------\n");
	printf("0. Salir\n");
	printf("1. Agregar alumnos\n");
	printf("2. Imprimir\n");
	printf("3. Alumnos Aprobados\n");
	printf("4. Alumnos Reprobados\n");
	printf("5. Promedio del grupo\n");
	printf("6. Porcentaje de aprobados\n");
	printf("----------------------------------\n");
	printf("Selecciona una opcion: ");
	scanf("%d",&opcion);
	return opcion;
}

void agregar(struct alumno x[]){
	int pregunta;
	while(n<MAX){
		leers("Nombre: ",x[n].nombre,30);
		x[n].promedio=leerf("Promedio: ",0,10);
		x[n].faltas=leerd("Faltas: ",0,32);
		n++;
		pregunta=leerd("Agregar otro alumno? (1-Si, 0-No) ",0,1);
		if(pregunta==0){
			break;
		}
	}
	if(n==MAX){
		printf("Arreglo lleno!!\n");
		system("PAUSE");
	}
}

void imprimir(struct alumno x[],int tipo, char *a){
	printf("----------------------Alumnos %s------------------\n",a);
	printf("No.\tNombre\t\t\t\tFaltas\tPromedio\n");
	printf("-------------------------------------------------------\n");
	for(int i=0;i<n;i++){
		switch(tipo){
			case 0: printf("%2d\t%-30s\t%-2d\t%4.1f\n",i+1,x[i].nombre,x[i].faltas,x[i].promedio);
					break;
			case 1: if(x[i].promedio>=7 && x[i].faltas<=6){
						printf("%2d\t%-30s\t%-2d\t%4.1f\n",i+1,x[i].nombre,x[i].faltas,x[i].promedio);
					}
					break;
			case 2: if(x[i].promedio<7 || x[i].faltas>6){
						printf("%2d\t%-30s\t%-2d\t%4.1f\n",i+1,x[i].nombre,x[i].faltas,x[i].promedio);
					}
					break;
		}
	}
	printf("-------------------------------------------------------\n");
}

void promedio(struct alumno x[]){
	float suma=0, prom;
	for(int i=0;i<n;i++){
		if(x[i].faltas<=6){
			suma=suma+x[i].promedio;	
		}
		else{
			suma=suma+5;
		}
	}
	prom=suma/n;
	printf("PROMEDIO DEL GRUPO\n");
	printf("------------------------------\n");
	printf("El promedio es de %.1f\n",prom);
	printf("------------------------------\n");
}

void porcentajeaprobados(struct alumno x[]){
	int apro=0;
	float porcentaje;
	for(int i=0;i<n;i++){
		if(x[i].promedio>=7 && x[i].faltas<=6){
			apro++;
		}
	}
	porcentaje=(float)(apro*100)/n;
	printf("PORCENTAJE DE APROBADOS DEL GRUPO\n");
	printf("------------------------------\n");
	printf("Aprobados %.2f%%\n",porcentaje);
	printf("------------------------------\n");
}
