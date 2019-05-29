#include <iostream>
#include <stdlib.h>
#include "tree.h"
#include "lista.h"

using namespace std;

NoTree *criarNoTree(int n){
    NoTree* ret = new NoTree;
    ret->dado = n;
    ret->dir = NULL;
    ret->esq = NULL;
    ret->pai = NULL;
    return ret;
}

int add(NoTree *noTree, int n){
    if(noTree != NULL){
        if(n < noTree->dado){
            //continua a funcao aqui adiciona na esquerda
            if(noTree->esq == NULL){
                noTree->esq = criarNoTree(n);
                noTree->esq->pai = noTree;
                return 1;
            }
            else
                return add(noTree->esq, n);
        }
        if(n >= noTree->dado){
            //continua a funcao aqui adiciona na direita
            if(noTree->dir == NULL){
                noTree->dir = criarNoTree(n);
                noTree->dir->pai = noTree;
                return 1;
            }
            else
                return add(noTree->dir, n);
        }
    }
    criarNoTree(n);
    return 1;
}

void emOrdem(NoTree* noTree){
    if(noTree != NULL && noTree->dado != NULL){
        emOrdem(noTree->esq);
        cout << noTree->dado << " ";
        emOrdem(noTree->dir);
    }
}

NoTree *busca(NoTree* noTree,int n){
    if(n < noTree->dado)//esquerda
        return busca(noTree->esq, n);
    if(n > noTree->dado)//direita
        return busca(noTree->dir, n);
    if(n == noTree->dado)
        return noTree;
}

NoTree *minimo(NoTree* noTree){
    NoTree* aux = noTree;
    while(aux->esq != NULL)
        aux = aux->esq;
    return aux;
}

NoTree* maximo(NoTree* noTree){
    NoTree* aux = noTree;
    while(aux->dir != NULL)
        aux = aux->dir;
    return aux;
}

int remover(NoTree* noTree, int n){
    if(noTree!= NULL){
        NoTree* aux = busca(noTree, n);
        if(aux->dir == NULL && aux->esq == NULL){ //caso 1 nenhum filho
            aux->dado = NULL;
            aux = NULL;
            return 1;
        }
        if(aux->dir == NULL && aux->esq != NULL){ //caso 2: 1 filho a esquerda
            if(aux == aux->pai->esq){ //filho a esquerda do pai
                aux->pai->esq = aux->esq;
                aux->esq->pai = aux->pai;
                aux = NULL;
            }else if(aux == aux->pai->dir){ //filho a direi ta do pai
                aux->pai->dir = aux->esq;
                aux->esq->pai = aux->pai;
                aux = NULL;
            }
        }else if(aux->esq == NULL && aux->dir != NULL){ //caso 2: 1 filho a direita
            if(aux == aux->pai->esq){ //filho a esquerda do pai
                aux->pai->esq = aux->dir;
                aux->dir->pai = aux->pai;
                aux = NULL;
            }else if(aux == aux->pai->dir){ // filho a direita do pai
                aux->pai->dir = aux->dir;
                aux->dir->pai = aux->pai;
                aux = NULL;
            }
        }
        if(aux->dir != NULL && aux->esq != NULL){// caso 3: tem 2 filhos (menoTreer valor do da direita)
            int aux2 = minimo(aux->dir)->dado;
            remover(noTree, aux2);
            aux->dado = aux2;
        }
        return 1;
    }
    return 0;
}

void imprimeFolhas(NoTree* noTree){
    if(noTree != NULL){
        imprimeFolhas(noTree->esq);
        if(noTree->esq == NULL && noTree->dir == NULL)
            cout << noTree->dado << " ";
        imprimeFolhas(noTree->dir);
    }
}

void imprimeNivel(NoTree* noTree, int n){
    if(noTree != NULL){
        if(n == 0)
            cout << noTree->dado << " ";
        imprimeNivel(noTree->esq, n-1);
        imprimeNivel(noTree->dir, n-1);
    }
}


