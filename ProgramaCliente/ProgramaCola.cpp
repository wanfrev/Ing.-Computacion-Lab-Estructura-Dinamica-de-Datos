//COLA DE UN USUARIO CON SU NOMBRE, CLAVE Y EDAD
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Cliente{
  char nombre[30];
  char clave[10];
  int edad;
};

struct Nodo{
  Cliente c;
  Nodo *siguiente;
};

void meterClientes(Cliente &);
void insertarCola(Nodo *&,Nodo *&,Cliente);
bool cola_vacia(Nodo *);
void suprimirCola(Nodo *&,Nodo *&,Cliente &);

int main(){
  Nodo *frente = NULL;
  Nodo *fin = NULL;
  Cliente c;
  int rpt;
  
  do{
    meterClientes(c); //Meter datos
    insertarCola(frente,fin,c); //Agregar un nuevo cliente
    
    printf("\nDesea agregar un nuevo cliente? (1 si / 0 no) ");
    scanf("%d",&rpt);
  }while(rpt==1);
  
  printf("\n\nLos clientes se agregaron exitosamente\n\n");
  
  printf("\tClientes agregados: \n\n");
  while(frente!=NULL){
    suprimirCola(frente,fin,c);
    
    printf("\nNombre: %s",c.nombre);
    printf("\nClave: %s",c.clave);
    printf("\nEdad: %d",c.edad);
    printf("\n");
  }
  
  return 0;
}

void meterClientes(Cliente &c){
  fflush(stdin);
  printf("\nAGREGAR CLIENTE\n");
  printf("Digite su nombre: ");
  scanf("%s",&c.nombre);
  printf("Clave: ");
  scanf("%s",&c.clave);
  printf("Edad: ");
  scanf("%d",&c.edad);
  fflush(stdin);
}

void insertarCola(Nodo *&frente,Nodo *&fin,Cliente c){
  struct Nodo *nuevo_nodo =  (struct Nodo*) malloc( sizeof (struct  Nodo));

    nuevo_nodo->c = c;
    nuevo_nodo->siguiente = NULL;
    
    if(cola_vacia(frente)){
      frente = nuevo_nodo;
  }else{
    fin->siguiente = nuevo_nodo;
  }
  
  fin = nuevo_nodo;
}

bool cola_vacia(Nodo *frente){
  if(frente==NULL){
    return true;
  }else{
    return false;
  }
}

void suprimirCola(Nodo *&frente,Nodo *&fin,Cliente &c){
  c = frente->c;
  
  Nodo *aux = frente;
  
  if(frente==fin){
    frente == NULL;
    fin == NULL;
  }else{
    frente = frente->siguiente;
  }
  
  delete aux;
}
