#include <iostream>
#include <fstream>
#include "lista.h"

using namespace std;

void ordenaLista(Lista **lista){
    if(*lista != NULL){
        No* aux1 = (*lista)->cab;
        No* aux2 = (*lista)->cab;
        string strtmp;
        int inttmp;

        while(aux1 != NULL){
            aux2 = aux1->prox;
            while(aux2 != NULL){
                if(aux1->palavra->ocorrencias <= aux2->palavra->ocorrencias){
                    strtmp = aux1->palavra->dado;
                    inttmp = aux1->palavra->ocorrencias;
                    aux1->palavra->dado = aux2->palavra->dado;
                    aux1->palavra->ocorrencias = aux2->palavra->ocorrencias;
                    aux2->palavra->dado = strtmp;
                    aux2->palavra->ocorrencias = inttmp;
                }
                aux2 = aux2->prox;
            }
            aux1 = aux1->prox;
        }
    }
}

Lista* criarLista(){
    Lista* lista = new Lista;
    lista->qtd = 0;
    lista->cab = NULL;
    lista->ult = NULL;

    string linha;
    ifstream arquivo ("arquivo.txt");
    if (arquivo.is_open()){
        while (getline(arquivo,linha)){
            addLista(&lista, linha);
        }
        arquivo.close();
    }
    ordenaLista(&lista);
    return lista;
}

No* criarNo(Palavra* palavra){

    if(palavra!= NULL){
        No* no = new No;
        no->palavra = new Palavra;
        no->prox = NULL;
        no->palavra->dado = palavra->dado;
        no->palavra->ocorrencias = palavra->ocorrencias;
        return no;
    }
}

void calculaOcorrencias(Lista **lista){
    if(*lista != NULL){
        No* aux = (*lista)->cab;
        while (aux != NULL){
            if(aux->palavra->dado == (*lista)->ult->palavra->dado){
                aux->palavra->ocorrencias++;
                (*lista)->ult->palavra->ocorrencias++;
            }
            aux = aux->prox;
        }
    }
}

void addLista(Lista **lista, string dado){
    if(*lista != NULL){
        Palavra *palavra = new Palavra;
        palavra->dado = dado;
        palavra->ocorrencias = -1;

        No* novo = criarNo(palavra);

        if((*lista)->qtd == 0){
            (*lista)->cab = novo;
            (*lista)->ult = (*lista)->cab;
        }
        else{
            (*lista)->ult->prox = novo;
            (*lista)->ult = (*lista)->ult->prox;
        }
        (*lista)->qtd ++;
        calculaOcorrencias(lista);
    }
}

void printaLista(Lista* lista){
    if (lista != NULL){
        No* aux = lista->cab;
        while(aux != NULL){
            cout << aux->palavra->dado << ": " << aux->palavra->ocorrencias;
            if(aux->prox != NULL)
                cout << "\n";
            aux = aux->prox;
        }
    }
}



