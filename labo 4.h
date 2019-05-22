#include <stdio.h>
#include <stdlib.h>
typedef struct struct_arbol{
	char valor;
	struct struct_arbol *hizq;
	struct struct_arbol *hder;
}nodo,*ptr;


nodo *creaNodo(char c){
	nodo *nuevo;
	nuevo=malloc(sizeof(nodo));
	nuevo->valor=c;
	nuevo->hizq=NULL;
	nuevo->hder=NULL;
	return nuevo;
}

nodo *creaArbol(FILE *p){
	char c;
	if(feof(p)){
		return NULL;
	}

	c=fgetc(p);
	if(c=='N'){
		return NULL;
	}
	else{
		nodo *nuevo=creaNodo(c);
		nuevo->hizq=creaArbol(p);
		nuevo->hder=creaArbol(p);
		return nuevo;
	}

}
