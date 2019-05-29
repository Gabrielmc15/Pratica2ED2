#include <iostream>
#include <stdio.h>
#include <string.h>
#include "hash.h"
#include "lista.h"


using namespace std;

void addHash(Hash * tabela[], int posicao, int dado){
    cout << "\n ADICIONANDO... \n";
    Hash* novo = new Hash;

    novo->dado = dado;
    novo->prox = tabela[posicao];
    tabela[posicao] = novo;

    cout << "\n Elemento " << novo->dado << " inserido com sucesso!";
}

//funcao hashing

int hashing (int numero, int tamanho){
    return (numero & 0x7FFFFFFF) %tamanho;
}

//imprimir tabela

void imprimeHash(Hash* tabela[],int tamanho){
    Hash *aux;
    int i;
    for(i=0; i<tamanho; i++){
        aux = tabela[i];
        while(aux != NULL){
            cout << "\n Entrada: " << i << " Chave: " << aux->dado;
            aux = aux->prox;
        }
    }
    cout << "\n";
}

//iniciar tabela
void iniciar(Hash* tabela[], int tamanho){
    int i;
    for(i=0; i<tamanho; i++){
        tabela[i]= NULL;
    }
}

int valorString (string str){
    int i, valor = 7;
    char copia[str.size() + 1];
    strcpy(copia, str.c_str());
    int tam = strlen(copia);

    for(i=0; i<tam; i++){
        valor = 31 * valor+(int) copia[i];
    }
    //cout << valor << endl;
    return valor;
}


//cria lista, le linhas do arquivo ordena com base nas ocorrencias e adiciona no hash
void criarHash(int tam){
    Lista* lista = criarLista();
    printaLista(lista);
    No* aux = lista->cab;
    Hash* tabela[tam];
    //Hash* aux;
    int posicao;

    iniciar(tabela,tam);

    while(aux != NULL){
        posicao = hashing(valorString (aux->palavra->dado), tam);
        addHash(tabela, posicao, valorString (aux->palavra->dado));
        aux = aux->prox;
    }
    imprimeHash(tabela, tam);
}



