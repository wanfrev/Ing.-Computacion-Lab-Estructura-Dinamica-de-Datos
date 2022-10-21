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
void borrarNodo();

int main(){
	int n,op;
	
	do{
		printf("\n\n1.Crear e ingresar datos a la lista");
		printf("\n2.Mostrar lista");
		printf("\n3.Vaciar lista");
		printf("\n4.SALIR");
		printf("\nDigite una opcion: ");
		scanf("%d",&op);
		switch(op){
			case 1:
				printf("\nDigite la cantidad de datos que desea ingresar: ");
				scanf("%d",&n);
				
				for(int i=0;i<n;i++){
					insertarNodo();
				}
				break;
			case 2:
				printf("\nLa lista es: ");
				mostrarLista();
				break;
			case 3:
				while(primero!=NULL){
					borrarNodo();
					printf("\nLa lista es: ");
					mostrarLista();
				}				
				break;
			case 4:
				break;
		}
	}while(op!=4);
	
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

void borrarNodo(){
	nodo *actual = (nodo*)malloc(sizeof(nodo));
	actual=primero;
	nodo* anterior = (nodo*)malloc(sizeof(nodo));
	anterior=NULL;
	
	int nodoBuscado=0,encontrado=0;
	printf("\nIngrese el nodo a eliminar: ");
	scanf("%d",&nodoBuscado);
	
	if(primero!=NULL){
		while(actual!=NULL && encontrado != 1){
			if(actual->dato == nodoBuscado){
				if(actual==primero){
				primero = primero->siguiente;
				}else if(actual == ultimo){
					anterior->siguiente = NULL;
					ultimo = anterior;
				}else{
					anterior->siguiente = actual->siguiente;
				}
				
				printf("\nNodo eliminado");
				encontrado=1;
			}	
			anterior = actual;
			actual = actual->siguiente;		
		}
		if(encontrado==0){
			printf("\nNodo no encontrado");
		}else{
			free(anterior);
		}	
	}else{
		printf("\nLista vacia");
	}	
}
