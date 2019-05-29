using namespace std;

typedef struct _Hash_{
  int dado;
  _Hash_* prox;
}Hash;

void addHash(Hash * tabela[], int posicao, int dado);

int hashing (int numero, int tamanho);

void imprimeHash(Hash* tabela[],int tamanho);

void iniciar(Hash* tabela[], int tamanho);

int valorString (string str);

void criarHash(int tam);



