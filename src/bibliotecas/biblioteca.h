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
    Registro *reg;
} Epilha;

typedef struct {
    Epilha *topo;
    int qtde;
} Pilha;

Lista *criaLista();
Elista *criaElista(Registro *r);
void inserirLista(Lista *l, Registro *r);
void removerLista(Lista *l, Registro *r);
void showLista(Lista *l);
Registro *criaRegistro() ;


Efila *criaEfila(Registro *r);
Fila *criaFila();
void enqueueFila(Fila *fila, Lista *lista, const char *rg);
int dequeueFila(Fila *fila);
void showFila(Fila *fila);

Epilha *criaEpilha(Fila *fila, Registro *reg);
Pilha *criaPilha();
void pushPilha(Pilha *pilha, Fila *fila, Registro *reg);
Registro *popPilha(Pilha *pilha);
void showPilha(Pilha *pilha);

ABB *criaABB();
void rotacaoEsquerdaABB(ABB *arv, EABB *v);
void rotacaoDireitaABB(ABB *arv, EABB *v);
int maxABB(int x, int y);
int alturaABB(EABB *x);
int fatorBalanceamentoABB(EABB *x);
void balanceieABB(ABB *arv, EABB *v);
int insereABBIdade(ABB *arv, Registro *reg);
int insereABBAno(ABB *arv, Registro *reg);
int insereABBMes(ABB *arv, Registro *reg);
int insereABBDia(ABB *arv, Registro *reg);
int removerABB(ABB *arvore, EABB *x);
int buscar_e_removerABBIdade(ABB *arvore, const char *rg);
int buscar_e_removerABBAno(ABB *arvore, const char *rg);
int buscar_e_removerABBMes(ABB *arvore, const char *rg);
int buscar_e_removerABBDia(ABB *arvore, const char *rg);
int getValorABB(ABB *arvore);
void imprimeInOrdemABB(EABB *raiz);
void insereABBGeral(ABB *arvi,ABB *arva,ABB *arvm,ABB *arvd, Registro *reg);
void removeABBGeral(ABB *arvi,ABB *arva,ABB *arvm,ABB *arvd, const char *rg);

Registro *criaRegistro();
int Cadastrar_novo_paciente(Lista *l, Registro *novoRegistro);
void Consultar_paciente_cadastrado(Lista *l, const char *rg);
int Atualizar_dados_de_paciente(Lista *l, const char *rg);
int Remover_paciente(Lista *l, const char *rg);

void imprimeDados(Registro *reg);

int Mostrar_por_ano(ABB *arv);
int Mostrar_por_mes(ABB *arv);
int Mostrar_por_dia(ABB *arv);
int Mostrar_por_idade(ABB *arv);

int salvarRegistros(Lista *l);
int carregarRegistros(Lista *l);
int salvarDatas(Lista *l);
int carregarDatas(Lista *l);

void Mostrar_dados_devs();

int menus(Lista *l, Fila *f, Pilha *p, ABB *arvi, ABB *arva, ABB *arvm, ABB *arvd);
void menuLista(Lista *l, ABB *arvIdade, ABB *arvAno, ABB *arvMes, ABB *arvDia);
void menuFila(Lista *l, Fila *f);
void menuArvore(Lista *l, ABB *arvi, ABB *arva, ABB *arvm, ABB *arvd);

#endif
