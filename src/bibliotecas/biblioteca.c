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


//-------------------------------Funções de manipulação de ABB--------------------------------//

ABB *criaABB(){
    ABB *arvore = malloc(sizeof(ABB));
    arvore->raiz = NULL;
    arvore->qtde = 0;
    return arvore;
}

void rotacaoEsquerdaABB(ABB *arv, EABB *v){
    if(v==NULL || v->dir == NULL){
        return;
    }
    EABB *temp = v->dir;
    v->dir = temp->esq;
    
    if (temp->esq != NULL) {
        temp->esq->pai = v;
    }

    temp->esq = v;

    temp->pai = v->pai;
    v->pai = temp;

    if(temp->pai == NULL){
        arv->raiz = temp;
    }else if(v == temp->pai->esq){
        temp->pai->esq = temp;
    } else {
        temp->pai->dir = temp;
    }

}
void rotacaoDireitaABB(ABB *arv, EABB *v){
    if(v==NULL || v->esq == NULL){
        return;
    }
    EABB *temp = v->esq;
    v->esq = temp->dir;

    if (temp->dir != NULL) {
        temp->dir->pai = v;
    }

    temp->dir = v;

    temp->pai = v->pai;
    v->pai = temp;

    if(temp->pai == NULL){
        arv->raiz = temp;
    }else if(v == temp->pai->esq){
        temp->pai->esq = temp;
    } else {
        temp->pai->dir = temp;
    }
}

int maxABB(int x, int y){
    if (x >= y)
        return x;
    else
        return y;
}
int alturaABB(EABB *x){
    if (x == NULL) {
        return -1;
    }
    return maxABB(alturaABB(x->esq), alturaABB(x->dir)) + 1;
}
int fatorBalanceamentoABB(EABB *x){
    return alturaABB(x->dir) - alturaABB(x->esq); 
}

void balanceieABB(ABB *arv, EABB *v){
    if(v == NULL){
        return;
    }
    else{
        int fb = fatorBalanceamentoABB(v);
        if(fb<-1 || fb>1){
            if(fb >= 2){
                if(fatorBalanceamentoABB(v->dir) >= 0){
                    rotacaoEsquerdaABB(arv, v);
                } else{
                    rotacaoDireitaABB(arv, v->dir);
                    rotacaoEsquerdaABB(arv, v);
                }
            }else if(fb <= -2){
                if(fatorBalanceamentoABB(v->esq) <= 0){
                    rotacaoDireitaABB(arv, v);
                } else{
                    rotacaoEsquerdaABB(arv, v->esq);
                    rotacaoDireitaABB(arv, v);
                }
            }
            balanceieABB(arv, v->pai);
        }
    }
}

int insereABBIdade(ABB *arv, Registro *reg){
    EABB *novo = malloc(sizeof(EABB));
    novo->dir = NULL;
    novo->esq = NULL;
    novo->pai = NULL;
    novo->dados = reg;

    EABB *anterior = NULL;
    EABB *atual = arv->raiz;

    while (atual != NULL) {
        anterior = atual;
        if (reg->idade <= atual->dados->idade) {
        atual = atual->esq;
        } else {
        atual = atual->dir;
        }
    }

    novo->pai = anterior;
    if (anterior != NULL) {
        if (reg->idade <= anterior->dados->idade) {
        anterior->esq = novo;
        } else {
        anterior->dir = novo;
        }
    } else {
        arv->raiz = novo;
    }
    arv->qtde++;

    EABB *temp = novo->pai;
    while (temp != NULL) {
        balanceieABB(arv, temp);
        temp = temp->pai;
    }
    return 1;
}

int insereABBAno(ABB *arv, Registro *reg){
    EABB *novo = malloc(sizeof(EABB));
    novo->dir = NULL;
    novo->esq = NULL;
    novo->pai = NULL;
    novo->dados = reg;

    EABB *anterior = NULL;
    EABB *atual = arv->raiz;

    while (atual != NULL) {
        anterior = atual;
        if (reg->Entrada->ano <= atual->dados->Entrada->ano) {
        atual = atual->esq;
        } else {
        atual = atual->dir;
        }
    }

    novo->pai = anterior;
    if (anterior != NULL) {
        if (reg->Entrada->ano <= anterior->dados->Entrada->ano) {
        anterior->esq = novo;
        } else {
        anterior->dir = novo;
        }
    } else {
        arv->raiz = novo;
    }
    arv->qtde++;

    EABB *temp = novo->pai;
    while (temp != NULL) {
        balanceieABB(arv, temp);
        temp = temp->pai;
    }
    return 1;
}

int insereABBMes(ABB *arv, Registro *reg){
    EABB *novo = malloc(sizeof(EABB));
    novo->dir = NULL;
    novo->esq = NULL;
    novo->pai = NULL;
    novo->dados = reg;

    EABB *anterior = NULL;
    EABB *atual = arv->raiz;

    while (atual != NULL) {
        anterior = atual;
        if (reg->Entrada->mes <= atual->dados->Entrada->mes) {
        atual = atual->esq;
        } else {
        atual = atual->dir;
        }
    }

    novo->pai = anterior;
    if (anterior != NULL) {
        if (reg->Entrada->mes <= anterior->dados->Entrada->mes) {
        anterior->esq = novo;
        } else {
        anterior->dir = novo;
        }
    } else {
        arv->raiz = novo;
    }
    arv->qtde++;

    EABB *temp = novo->pai;
    while (temp != NULL) {
        balanceieABB(arv, temp);
        temp = temp->pai;
    }
    return 1;
}

int insereABBDia(ABB *arv, Registro *reg){
    EABB *novo = malloc(sizeof(EABB));
    novo->dir = NULL;
    novo->esq = NULL;
    novo->pai = NULL;
    novo->dados = reg;

    EABB *anterior = NULL;
    EABB *atual = arv->raiz;

    while (atual != NULL) {
        anterior = atual;
        if (reg->Entrada->dia <= atual->dados->Entrada->dia) {
        atual = atual->esq;
        } else {
        atual = atual->dir;
        }
    }

    novo->pai = anterior;
    if (anterior != NULL) {
        if (reg->Entrada->dia <= anterior->dados->Entrada->dia) {
        anterior->esq = novo;
        } else {
        anterior->dir = novo;
        }
    } else {
        arv->raiz = novo;
    }
    arv->qtde++;

    EABB *temp = novo->pai;
    while (temp != NULL) {
        balanceieABB(arv, temp);
        temp = temp->pai;
    }
    return 1;
}

int removerABB(ABB *arvore, EABB *x){
    int filhos = 0;

    if (x != NULL && x->esq != NULL) {
        filhos++;
    }
    if (x != NULL && x->dir != NULL) {
        filhos++;
    }

    EABB *pai = x->pai;
    if (filhos == 0) {
        if (pai != NULL) {
        if (pai->esq == x) {
            pai->esq = NULL;
        } else {
            pai->dir = NULL;
        }
        } else {
        arvore->raiz = NULL;
        }
        arvore->qtde--;
    } else if (filhos == 1) {
        EABB *filho = x->esq;
        if (filho == NULL)
        filho = x->dir;

        if (pai == NULL)
        arvore->raiz = filho;
        else {
        if (pai->esq == x)
            pai->esq = filho;
        else
            pai->dir = filho;
        }
        filho->pai = pai;
        arvore->qtde--;
    } else {
        EABB *sucessor = x;
        sucessor = sucessor->dir;
        while (sucessor->esq != NULL)
        sucessor = sucessor->esq;
        x->dados = sucessor->dados;
        return removerABB(arvore, sucessor);
    }

    return 1;
}
int buscar_e_removerABBIdade(ABB *arvore, const char *rg){
    EABB *anterior = arvore->raiz;
    EABB *atual = anterior;
    while (atual != NULL) {
        if (strcmp(atual->dados->rg, rg) == 0)
            return removerABB(arvore, atual);
        else if (anterior->dados->idade <= atual->dados->idade){
            anterior = atual;
            atual = atual->esq;
        }
        else if (anterior->dados->idade > atual->dados->idade){
            anterior = atual;
            atual = atual->dir;
        }
    }
    return 0;
}

int buscar_e_removerABBAno(ABB *arvore, const char *rg){
    EABB *anterior = arvore->raiz;
    EABB *atual = anterior;
    while (atual != NULL) {
        if (strcmp(atual->dados->rg, rg) == 0)
            return removerABB(arvore, atual);
        else if (anterior->dados->Entrada->ano <= atual->dados->Entrada->ano){
            anterior = atual;
            atual = atual->esq;
        }
        else if (anterior->dados->Entrada->ano > atual->dados->Entrada->ano){
            anterior = atual;
            atual = atual->dir;
        }
    }
    return 0;
}

int buscar_e_removerABBMes(ABB *arvore, const char *rg){
    EABB *anterior = arvore->raiz;
    EABB *atual = anterior;
    while (atual != NULL) {
        if (strcmp(atual->dados->rg, rg) == 0)
            return removerABB(arvore, atual);
        else if (anterior->dados->Entrada->mes <= atual->dados->Entrada->mes){
            anterior = atual;
            atual = atual->esq;
        }
        else if (anterior->dados->Entrada->mes > atual->dados->Entrada->mes){
            anterior = atual;
            atual = atual->dir;
        }
    }
    return 0;
}

int buscar_e_removerABBDia(ABB *arvore, const char *rg){
    EABB *anterior = arvore->raiz;
    EABB *atual = anterior;
    while (atual != NULL) {
        if (strcmp(atual->dados->rg, rg) == 0)
            return removerABB(arvore, atual);
        else if (anterior->dados->Entrada->ano <= atual->dados->Entrada->ano){
            anterior = atual;
            atual = atual->esq;
        }
        else if (anterior->dados->Entrada->ano > atual->dados->Entrada->ano){
            anterior = atual;
            atual = atual->dir;
        }
    }
    return 0;
}

void imprimeInOrdemABB(EABB *raiz){
    if (raiz != NULL) {
    imprimeInOrdemABB(raiz->esq);
    imprimeDados(raiz->dados);
    imprimeInOrdemABB(raiz->dir);
  }
}

void insereABBGeral(ABB *arvi,ABB *arva,ABB *arvm,ABB *arvd, Registro *reg){
    insereABBIdade(arvi,reg);
    insereABBAno(arva,reg);
    insereABBMes(arvm,reg);
    insereABBDia(arvd,reg);
}

void removeABBGeral(ABB *arvi,ABB *arva,ABB *arvm,ABB *arvd, const char *rg){
    buscar_e_removerABBIdade(arvi, rg);
    buscar_e_removerABBAno(arva, rg);
    buscar_e_removerABBMes(arvm, rg);
    buscar_e_removerABBDia(arvd, rg);
}

//-------------------------------Funções de manipulação de ABB--------------------------------//

void imprimeDados(Registro *reg){
    printf("Nome: %s\n", reg->nome);
    printf("Idade: %d\n", reg->idade);
    printf("RG: %s\n", reg->rg);
    printf("Data de Entrada: %02d/%02d/%04d\n\n", 
            reg->Entrada->dia, 
            reg->Entrada->mes, 
            reg->Entrada->ano);
}


int Mostrar_por_ano(ABB *arv);
int Mostrar_por_mes(ABB *arv);
int Mostrar_por_dia(ABB *arv);
int Mostrar_por_idade(ABB *arv);

int salvarRegistros(Lista *l);
int carregarRegistros(Lista *l);



