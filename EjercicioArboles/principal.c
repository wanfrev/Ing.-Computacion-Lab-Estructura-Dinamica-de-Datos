//CREAR UN ARBOL DONDE EL USUARIO DIGITA LA CANTIDAD DE NUMEROS A INGRESAR, ELIMINA UN NODO Y MUESTRA EN POSTORDEN, PREORDEN Y ENORDEN
#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int main(){
	Arbol *a=crearArbol();
	int cantN,num,numE;
	int i;
	
	printf("Digite la cantidad de numeros a ingresar: ");
	scanf("%d",&cantN);
	for(i=0;i<=cantN;i++){
		printf("Ingrese un numero: ");
		scanf("%d",&num);
		insertarNodo(a,crearNodo(num));
	}
	
	imprimirEnorden(a);
	
	printf("\n\nDigite el numero que desea eliminar: ");
	scanf("%d",&numE);
	eliminarNodo(a,numE);
	
	printf("\n");
	
	printf("\t\n\nPOSTORDEN");
	imprimirPostorden(a);
	
	printf("\t\n\nPREORDEN");
	imprimirPreorden(a);
	
	printf("\t\n\nENORDEN");
	imprimirEnorden(a);
	
	return 0;
}

