#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Lista *criaLista();
Elista *criaElista(Registro *r);
void inserirLista(Lista *l, Registro *r);
void removerLista(Lista *l, Registro *r);
void showLista(Lista *l);


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


int Cadastrar_novo_paciente();
int Consultar_paciente_cadastrado();
int Atualizar_dados_de_paciente(Lista *l, Registro *r);
int Remover_paciente(Lista *l, Registro *r);

int Mostrar_por_ano(ABB *arv);
int Mostrar_por_mes(ABB *arv);
int Mostrar_por_dia(ABB *arv);
int Mostrar_por_idade(ABB *arv);

int salvarRegistros(Lista *l);
int carregarRegistros(Lista *l);

void Mostrar_dados_devs();
