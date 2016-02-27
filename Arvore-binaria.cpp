#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct no{
    no *esq, *dir;
    int valor;
};
void inicia(no **raiz){
    *raiz = NULL;
}
void insere(no **raiz, int valor){
  if(*raiz == NULL){
    *raiz = (no *) malloc(sizeof(no));
    (*raiz)->esq = (*raiz)->dir = NULL;
    (*raiz)->valor = valor;
    return;
  }
  if(valor < (*raiz)->valor)
    insere(&(*raiz)->esq, valor);
  else if(valor >(*raiz)->valor);
    insere (&(*raiz)->dir, valor);
}

void caminha(no *raiz){
 if(raiz != NULL){
 caminha(raiz->dir);
 caminha(raiz->esq);
  printf("\n %d", raiz->valor);
 }
}
int main()
{
     no *arvore;
     inicia(&arvore);
     if(arvore == NULL)
        printf(" ARVORE VAZIA ");
     insere(&arvore , 150);
     insere(&arvore , 140);
     insere(&arvore , 165);
     caminha(arvore);
    return 0;
}

