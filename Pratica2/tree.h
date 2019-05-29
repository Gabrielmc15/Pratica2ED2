using namespace std;

///struct do noTree com o dado como inteiro e dois ponteiros um para a esquerda e outro para a direita
typedef struct _NoTree_{
    int dado;
    string palavra;
    _NoTree_ *esq, *dir, *pai;
}NoTree;


/**
NoTree *criarNoTree(int n)- cria uma arvore
@param n- inteiro que sera a raiz da arvore
@return uma arvore alocada
*/
NoTree *criarNoTree(int n);

/**
int add(NoTree* noTree, int n)- adiciona um dado em uma arvore ja alocada
@param *noTree- a arvore em que deseja adicionar
@param n-o dado que sera adicionado na arvore
@return- 1 sucesso, 0 falha
*/
int add(NoTree *noTree, int n);

/**
void emOrdem(NoTree* noTree)- imprime a arvore em ordem crescente
@param *noTree- a arvore que deseja imprimir
*/
void emOrdem(NoTree* noTree);

/**
NoTree *minimo(NoTree* noTree)- retorna o menoTreer dado da arvore(ultimo a esquerda)
@param *noTree- arvore
@return- noTree que contem o menoTreer dado
*/
NoTree *minimo(NoTree* noTree);

/**
NoTree *maximo(NoTree* noTree)- retorna o maior dado da arvore(ultimo a direita)
@param *noTree- arvore
@return- noTree que contem o menoTreer dado
*/
NoTree* maximo(NoTree* noTree);

/**
int remover(NoTree* noTree, int n)- remove o dado da arvore
@param *noTree- arvore
@param n- dado a ser removido
@return- 1 sucesso, 0 falha
*/
int remover(NoTree* noTree, int n);

/**
NoTree *busca(NoTree* noTree, int n)-funcao de busca na arvore
@param *noTree- arvore
@param n- o valor que deseja buscar
@return- o noTree com o dado da busca em caso de sucesso, NULL em caso de falha
*/
NoTree *busca(NoTree* noTree,int n);


///funcoes das atividades////////////////////////////

void imprimeFolhas(NoTree* noTree);

void imprimeNivel(NoTree* noTree, int n);


//////////////////////////////////////////////////



