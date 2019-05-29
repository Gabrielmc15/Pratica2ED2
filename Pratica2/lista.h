using namespace std;

typedef struct _Palavra_{
    string dado;
    int ocorrencias;
}Palavra;

typedef struct _No_{
    Palavra* palavra;
    _No_ * prox;
}No;

typedef struct _Lista_{
    int qtd;
    No* cab;
    No* ult;
}Lista;

void ordenaLista(Lista **lista);

Lista* criarLista();

No* criarNo(Palavra* palavra);

void calculaOcorrencias(Lista **lista);

void addLista(Lista **lista, string dado);

void printaLista(Lista* lista);






