#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-------------------------------Desenvolvedores--------------------------------//
void Mostrar_dados_devs(){
    printf("Desenvolvedores:\n");
    printf("Nome: Pedro Henrique Satoru Lima Takahashi \n");
    printf("RA: 22.123.019-6\n");
    printf("Nome: Pedro Henrique Correia de Oliveira\n");
    //Corrigir o RA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    printf("RA: 22.123.000-0\n");
    printf("4º Semestre\n");
    printf("Curso: Ciencias da Computação\n");
    printf("Disciplina: Estrutura de Dados\n");
    printf("Data de entrega: 14/11/2024");
}

//-------------------------------Funções de manipulação de listas--------------------------------//
Lista *criaLista(){
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->qtde = 0;
    l->inicio = NULL;
    return l;
}
Elista *criaElista(Registro *r){
    Elista *el = (Elista *)malloc(sizeof(Elista));
    el->dados = r;
    el->proximo = NULL;
    return el;
}
void inserirLista(Lista *l, Registro *r){
    Elista *paciente = criaElista(r);
    if(l->inicio == NULL){
        l->inicio = paciente;
    }else{
        Elista *aux = l->inicio;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = paciente;
    }
    l->qtde++;
}
void removerLista(Lista *l, Registro *r){
    if (l->inicio == NULL) return; 
    
    Elista *atual = l->inicio;
    Elista *anterior = NULL;
    
    while (atual != NULL && atual->dados != r) {
        anterior = atual;
        atual = atual->proximo;
    }
    
    if (atual == NULL) return; 
    
    if (anterior == NULL) {
        l->inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }
    
    free(atual);
    l->qtde--;
}
void showLista(Lista *l){
     Elista *atual = l->inicio;
    while (atual != NULL) {
        printf("Nome: %s\n", atual->dados->nome);
        printf("Idade: %d\n", atual->dados->idade);
        printf("RG: %s\n", atual->dados->rg);
        printf("Data de Entrada: %02d/%02d/%04d\n\n", 
               atual->dados->Entrada->dia, 
               atual->dados->Entrada->mes, 
               atual->dados->Entrada->ano);
        atual = atual->proximo;
    }
}

Registro *criaRegistro() {
    Registro *r = (Registro *)malloc(sizeof(Registro));
    r->Entrada = (Data *)malloc(sizeof(Data));
    
    printf("Digite o nome do paciente: ");
    fgets(r->nome, sizeof(r->nome), stdin);
    r->nome[strcspn(r->nome, "\n")] = '\0';  // Remove o '\n' do final
    
    printf("Digite a idade do paciente: ");
    scanf("%d", &r->idade);
    
    printf("Digite o RG do paciente: ");
    scanf("%s", r->rg);
    
    printf("Digite o dia da entrada: ");
    scanf("%d", &r->Entrada->dia);
    
    printf("Digite o mês da entrada: ");
    scanf("%d", &r->Entrada->mes);
    
    printf("Digite o ano da entrada: ");
    scanf("%d", &r->Entrada->ano);
    
    getchar(); 
    return r;
}

int Cadastrar_novo_paciente(Lista *l){
    Registro *novoRegistro = criaRegistro();
    inserirLista(l, novoRegistro);
    printf("Paciente cadastrado com sucesso!\n");
    return 1;
}


void Consultar_paciente_cadastrado(Lista *l, const char *rg){
    Elista *atual = l->inicio;
    while (atual != NULL) {
        if (strcmp(atual->dados->rg, rg) == 0) {
            printf("Nome: %s\n", atual->dados->nome);
            printf("Idade: %d\n", atual->dados->idade);
            printf("RG: %s\n", atual->dados->rg);
            printf("Data de Entrada: %02d/%02d/%04d\n\n", 
                   atual->dados->Entrada->dia, 
                   atual->dados->Entrada->mes, 
                   atual->dados->Entrada->ano);
            return 0;
        }
        atual = atual->proximo;
    }
    printf("Paciente não encontrado!\n");
    
}
int Atualizar_dados_de_paciente(Lista *l, const char *rg){
    Elista *atual = l->inicio;

    // Percorre a lista para encontrar o paciente com o RG correspondente
    while (atual != NULL) {
        if (strcmp(atual->dados->rg, rg) == 0) {  // Verifica se o RG corresponde
            printf("\nPaciente encontrado. Insira os novos dados:\n");

            printf("Digite o novo nome do paciente: ");
            fgets(atual->dados->nome, sizeof(atual->dados->nome), stdin);
            atual->dados->nome[strcspn(atual->dados->nome, "\n")] = '\0';  // Remove o '\n'

            printf("Digite a nova idade do paciente: ");
            scanf("%d", &atual->dados->idade);
            getchar(); 

            printf("Digite o novo RG do paciente: ");
            scanf("%s", atual->dados->rg);
            getchar(); 

            printf("Digite o novo dia da entrada: ");
            scanf("%d", &atual->dados->Entrada->dia);

            printf("Digite o novo mês da entrada: ");
            scanf("%d", &atual->dados->Entrada->mes);

            printf("Digite o novo ano da entrada: ");
            scanf("%d", &atual->dados->Entrada->ano);
            getchar(); 

            printf("Dados atualizados com sucesso!\n");
            return;
        }
        atual = atual->proximo;
    }

    printf("Paciente com RG %s não encontrado.\n", rg);
}
int Remover_paciente(Lista *l, const char *rg){
    Elista *atual = l->inicio;
    while (atual != NULL) {
        if (strcmp(atual->dados->rg, rg) == 0) {
            printf("Paciente removido com sucesso!\n");
            printf("Nome: %s\n", atual->dados->nome);
            printf("Idade: %d\n", atual->dados->idade);
            printf("RG: %s\n", atual->dados->rg);
            printf("Data de Entrada: %02d/%02d/%04d\n\n",
                   atual->dados->Entrada->dia,
                   atual->dados->Entrada->mes,
                   atual->dados->Entrada->ano);
            removerLista(l, atual->dados);
            return 1;
        }
        atual = atual->proximo;
    }
    printf("Paciente não encontrado!\n");
    return 0;
}

//-------------------------------Funções de manipulação de listas--------------------------------//


//-------------------------------Funções de manipulação de filas--------------------------------//

Efila *criaEfila(Registro *r){
    Efila *ef = (Efila *)malloc(sizeof(Efila));
    ef->dados = r;
    ef->proximo = NULL;
    return ef;
}
Fila *criaFila(){
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->head = NULL;
    f->tail = NULL;
    f->qtde = 0;
    return f;
}

 
void enqueueFila(Fila *fila, Lista *lista, const char *rg) {
    Elista *atual = lista->inicio;

    // Percorre a lista para encontrar o paciente com o RG correspondente
    while (atual != NULL) {
        if (strcmp(atual->dados->rg, rg) == 0) {
            // Paciente encontrado, agora cria o nó da fila com esse paciente
            Efila *paciente = criaEfila(atual->dados);

            if (fila->head == NULL) {
                // Se a fila está vazia, inicializa com o novo paciente
                fila->head = paciente;
                fila->tail = paciente;
            } else {
                // Caso contrário, adiciona ao final da fila
                fila->tail->proximo = paciente;
                fila->tail = paciente;
            }
            fila->qtde++;
            printf("Paciente com RG %s enfileirado com sucesso!\n", rg);
            return;
        }
        atual = atual->proximo;
    }

    // Se o paciente não for encontrado na lista
    printf("Paciente com RG %s não encontrado na lista.\n", rg);
}

int dequeueFila(Fila *fila){
    if(fila->head == NULL){
        return 0;
    }

    Efila *aux = fila->head;

    printf("Desenfileirando o paciente:\n");
    printf("Nome: %s\n", aux->dados->nome);
    printf("Idade: %d\n", aux->dados->idade);
    printf("RG: %s\n", aux->dados->rg);
    printf("Data de Entrada: %02d/%02d/%04d\n\n",
           aux->dados->Entrada->dia,
           aux->dados->Entrada->mes,
           aux->dados->Entrada->ano);


    fila->head = fila->head->proximo;
    free(aux);
    fila->qtde--;

    return 1;
}
void showFila(Fila *fila){
    Efila *aux = fila->head;
    int posicao = 1;
    while(aux != NULL){
        printf("Paciente %d:\n", posicao++);
        printf("Nome: %s\n", aux->dados->nome);
        printf("Idade: %d\n", aux->dados->idade);
        printf("RG: %s\n", aux->dados->rg);
        printf("Data de Entrada: %02d/%02d/%04d\n\n", 
               aux->dados->Entrada->dia, 
               aux->dados->Entrada->mes, 
               aux->dados->Entrada->ano);
        aux = aux->proximo;
    }
}

//-------------------------------Funções de manipulação de filas--------------------------------//

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



int Mostrar_por_ano(ABB *arv);
int Mostrar_por_mes(ABB *arv);
int Mostrar_por_dia(ABB *arv);
int Mostrar_por_idade(ABB *arv);

int salvarRegistros(Lista *l);
int carregarRegistros(Lista *l);



