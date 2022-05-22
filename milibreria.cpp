#include "milibreria.h"

float leerf(char *mensaje, float inferior, float superior){
	printf(mensaje);
	float valor;
	do{
		scanf("%f",&valor);
		if(valor<inferior || valor>superior){
			printf("Dato invalido !!!, Debe estar entre(%.2f-%.2f). Vuelva a introducirlo\n",inferior,superior);
		}
	}while(valor<inferior || valor>superior);
	return valor;
}

int leerd(char *mensaje, int inferior, int superior){
	printf(mensaje);
	int valor;
	do{
		scanf("%d",&valor);
		if(valor<inferior || valor>superior){
			printf("Dato invalido !!!, Debe estar entre(%d-%d). Vuelva a introducirlo\n",inferior,superior);
		}
	}while(valor<inferior || valor>superior);
	return valor;
}

void leers(char *mensaje,char s[],int n){
	printf(mensaje);
	fflush(stdin);
	fgets(s,n,stdin);
	fflush(stdin);
	if(s[strlen(s)-1]=='\n'){
		s[strlen(s)-1]=0;
	}
}
