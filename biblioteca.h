#ifndef biblioteca_h
#define biblioteca_h    

typedef struct {
    int dia;
    int mes;
    int ano;
}Data;

typedef struct {
    char nome[100];
    int idade;
    char rg[10];
    Data *Entrada;
}Registro;

typedef struct Elista {
    Registro *dados;
    struct Elista *proximo;
} Elista;

typedef struct Lista {
    int qtde;
    Elista *inicio;
} Lista;

typedef struct Efila {
    struct Efila *proximo;
    Registro *dados;
} Efila;

typedef struct {
    Efila *head;
    Efila *tail;
    int qtde;
} Fila;

typedef struct EABB {
  Registro *dados;
  struct EABB *esq;
  struct EABB *dir;
  struct EABB *pai;
} EABB;

typedef struct ABB {
  EABB *raiz;
  int qtde;
} ABB;

typedef struct Epilha {
    struct Epilha *proximo;
    Fila *fila;
    Lista *lista;
} Epilha;

typedef struct {
    Epilha *topo;
    int qtd;
} Pilha;

Lista *criaLista();
Elista *criaElista(Registro *r);
void inserirLista(Lista *l, Registro *r);
void removerLista(Lista *l, Registro *r);
void showLista(Lista *l);
Registro *criaRegistro() ;


Efila *criaEfila(Registro *r);
Fila *criaFila();
void enqueueFIla(Fila *fila, Registro *r);
int dequeueFila(Fila *fila);
void showFila(Fila *fila);

Epilha *criaEpilha(Fila *fila, Lista *lista);
Pilha *criaPilha();
void pushPilha(Pilha *pilha, Fila *fila, Lista *lista);
int popPilha(Pilha *pilha);
void showPilha(Pilha *pilha);

void rotacaoEsquerdaABB(ABB *arv, EABB *v);
void rotacaoDireitaABB(ABB *arv, EABB *v);
int maxABB(int x, int y);
int alturaABB(EABB *x);
int fatorBalanceamentoABB(EABB *x);
void balanceieABB(ABB *arv, EABB *v);
int insereABB(ABB *arv, Registro *reg);
int removerABB(ABB *arvore, EABB *x);
int buscar_e_removerABB(ABB *arvore, Registro *registro);
int getValorABB(ABB *arvore);
void imprimeInOrdemABB(EABB *raiz, int x);

Registro *criaRegistro();
int Cadastrar_novo_paciente(Lista *l);
void Consultar_paciente_cadastrado(Lista *l, const char *rg);
int Atualizar_dados_de_paciente(Lista *l, const char *rg);
int Remover_paciente(Lista *l, const char *rg);

int Mostrar_por_ano(ABB *arv);
int Mostrar_por_mes(ABB *arv);
int Mostrar_por_dia(ABB *arv);
int Mostrar_por_idade(ABB *arv);

int salvarRegistros(Lista *l);
int carregarRegistros(Lista *l);

void Mostrar_dados_devs();

#endif
