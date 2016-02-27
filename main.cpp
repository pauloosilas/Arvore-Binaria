#include <iostream>
#include <stdlib.h>

using namespace std;


typedef struct NO *arvBin;

struct NO{

    int info;
    struct NO *esq;
    struct NO *dir;
};

arvBin *raiz;

arvBin* cria_arvore(struct NO* no);
void libera_ArvBin(arvBin *raiz);
void libera_NO(struct NO* no);
int esta_vazia(arvBin* raiz);


arvBin* cria_arvore(){
    arvBin* raiz = (arvBin*) malloc(sizeof(arvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
    }

void libera_NO(struct NO* no){
    if(no == NULL)
        return;

    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);

    no = NULL;

}

void libera_ArvBin(arvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);
    free(raiz);

}
int esta_vazia(arvBin* raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;

    return 0;

}

int main()
{
    arvBin* raiz = cria_arvore();
    int valor = esta_vazia(raiz);

    cout << valor;

    return 0;
}
