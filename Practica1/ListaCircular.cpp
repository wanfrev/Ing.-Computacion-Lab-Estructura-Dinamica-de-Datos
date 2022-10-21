#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct nodo{
	int dato;
	struct nodo* siguiente;
} nodo;

nodo* primero = NULL;
nodo* ultimo = NULL;

void insertarNodo();
void mostrarLista();

int main(){
	int n;
	
	printf("\nDigite la cantidad de datos que desea ingresar: ");
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		insertarNodo();
	}
	
	printf("\nLa lista es: ");
	mostrarLista();
	
	return 0;
}

void insertarNodo(){
	nodo* nuevo = (nodo*)malloc(sizeof(nodo));
	printf("Ingrese un dato: ");
	scanf("%d",&nuevo->dato); 
	
	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = primero; //Se llama a si mismo
		ultimo = primero;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = primero;
		ultimo = nuevo;
	}
	
}

void mostrarLista(){
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	if(primero==NULL){
		printf("\nLa lista se encuentra vacia");
	}else{
		do{
			printf("\n %d",actual->dato);
			actual = actual->siguiente;
		}while(actual!=primero);
	}
}
