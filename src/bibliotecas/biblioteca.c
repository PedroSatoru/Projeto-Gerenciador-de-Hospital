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
    
    printf("RA: 22.222.009-7\n");
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
    imprimeDados(r);
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

int Cadastrar_novo_paciente(Lista *l, Registro *novoRegistro){
    inserirLista(l, novoRegistro);
    salvarRegistros(l);
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
            return;
        }
        atual = atual->proximo;
    }
    printf("Paciente não encontrado!\n");
    
}
int Atualizar_dados_de_paciente(Lista *l, const char *rg, ABB *arvi, ABB *arva, ABB* arvm, ABB *arvd){
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

            salvarRegistros(l);
            removeABBGeral(arvi, arva, arvm, arvd, atual->dados);
            insereABBGeral(arvi, arva, arvm, arvd, atual->dados);
            printf("Dados atualizados com sucesso!\n");
            return 1;
        }
        atual = atual->proximo;
    }

    printf("Paciente com RG %s não encontrado.\n", rg);
    return 0;
}
int Remover_paciente(Lista *l, const char *rg, ABB *arvi, ABB *arva, ABB* arvm, ABB *arvd){
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
            printf("3");
            removeABBGeral(arvi, arva, arvm, arvd, atual->dados);
            removerLista(l, atual->dados);
            printf("2");
            salvarRegistros(l);
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

 
void enqueueFila(Fila *fila, Lista *lista, const char *rg, Pilha *pilha) {
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
            pushPilha(pilha, 1, paciente->dados);
            printf("Paciente com RG %s enfileirado com sucesso!\n", rg);
            return;
        }
        atual = atual->proximo;
    }

    // Se o paciente não for encontrado na lista
    printf("Paciente com RG %s não encontrado na lista.\n", rg);
}

int dequeueFila(Fila *fila, Pilha *pilha){
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
    pushPilha(pilha, 2, aux->dados);
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

void desfazer(Pilha *pilha, Fila *fila){
    char opcao;
    if(pilha->topo->op == 1){
        printf("Deseja desfazer a insercao de %s na fila? (s/n): ", pilha->topo->reg->nome);
        scanf("%c", &opcao);
        getchar();
        if(opcao == 's'){
            Efila *aux = fila->head;
            if(aux == fila->tail){
                fila->head = NULL;
                fila->tail = NULL;
            } else {
                Efila *ant = NULL;
                while(aux->proximo != NULL){
                    ant = aux;
                    aux = aux->proximo;
                }
                fila->tail = ant;
                ant->proximo = NULL;
            }
            free(aux);
            popPilha(pilha);
            fila->qtde--;
            printf("Paciente removido da fila!\n\n");
             
        } else {
            printf("Operacao cancelada!\n\n");
        }
    } else if(pilha->topo->op == 2){
        char opcao;
        printf("Deseja desfazer a remocao de %s na fila? (s/n): ", pilha->topo->reg->nome);
        scanf("%c", &opcao);
        getchar();
        if(opcao == 's'){
            Efila *aux = criaEfila(pilha->topo->reg);
            aux->proximo = fila->head;
            fila->head = aux;
            fila->qtde++;
            popPilha(pilha);
            printf("Paciente reinserido na fila!\n\n");
        } else{
            printf("Operacao cancelada!\n\n");
        }
    }
}

//-------------------------------Funções de manipulação de pilhass--------------------------------//

Epilha *criaEpilha(int op, Registro *reg){
    Epilha *epilha = malloc(sizeof(Epilha));
    epilha->proximo = NULL;
    epilha->op = op;
    epilha->reg = reg;

    return epilha;
}
Pilha *criaPilha(){
    Pilha *pilha = malloc(sizeof(Pilha));
    pilha->topo = NULL;
    pilha->qtde = 0;

    return pilha;
}
void pushPilha(Pilha *pilha, int op, Registro *reg){
    Epilha *novo = criaEpilha(op, reg);
    novo->proximo = pilha->topo;
    pilha->topo = novo;
    pilha->qtde++;
}
Registro *popPilha(Pilha *pilha){
    Registro *reg = pilha->topo->reg;
    if(pilha->qtde==0){
        printf("Stack Overflow\n");
        return reg;
    }
    Epilha *temp = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    pilha->qtde--;
    free(temp);
    return reg;
}

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
int buscar_e_removerABBIdade(ABB *arvore, Registro *reg){
    EABB *atual = arvore->raiz;
    while (atual != NULL) {
        if (strcmp(atual->dados->rg, reg->rg) == 0)
            return removerABB(arvore, atual);
        else if (reg->idade <= atual->dados->idade){
            atual = atual->esq;
        }
        else if (reg->idade > atual->dados->idade){
            atual = atual->dir;
        }
    }
    return 0;
}

int buscar_e_removerABBAno(ABB *arvore, Registro *reg){
    EABB *atual = arvore->raiz;
    while (atual != NULL) {
        if (strcmp(atual->dados->rg, reg->rg) == 0)
            return removerABB(arvore, atual);
        else if (reg->Entrada->ano <= atual->dados->Entrada->ano){
            atual = atual->esq;
        }
        else if (reg->Entrada->ano > atual->dados->Entrada->ano){
            atual = atual->dir;
        }
    }
    return 0;
}

int buscar_e_removerABBMes(ABB *arvore, Registro *reg){
    EABB *atual = arvore->raiz;
    while (atual != NULL) {
        if (strcmp(atual->dados->rg, reg->rg) == 0)
            return removerABB(arvore, atual);
        else if (reg->Entrada->mes <= atual->dados->Entrada->mes){
            atual = atual->esq;
        }
        else if (reg->Entrada->mes > atual->dados->Entrada->mes){
            atual = atual->dir;
        }
    }
    return 0;
}

int buscar_e_removerABBDia(ABB *arvore, Registro *reg){
    EABB *atual = arvore->raiz;
    imprimeDados(reg);
    while (atual != NULL) {
        if (strcmp(atual->dados->rg, reg->rg) == 0){
            return removerABB(arvore, atual);
        }
        else if (reg->Entrada->dia <= atual->dados->Entrada->dia){
            atual = atual->esq;
        }
        else if (reg->Entrada->dia > atual->dados->Entrada->dia){
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

void removeABBGeral(ABB *arvi,ABB *arva,ABB *arvm,ABB *arvd, Registro *reg){
    printf("1");
    buscar_e_removerABBIdade(arvi, reg);
    buscar_e_removerABBAno(arva, reg);
    buscar_e_removerABBMes(arvm, reg);
    buscar_e_removerABBDia(arvd, reg);
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


//--------------------------------------Funções de manipulação de arquivos--------------------------------------//

//Função para salvar as structs em um arquivo binário
int salvarRegistros(Lista *l){
    Registro regs[l->qtde];
    Elista *inicio = l->inicio;
    for(int i=0; i<l->qtde; i++){
        regs[i] = *inicio->dados;
        inicio = inicio->proximo;
    }
    //Abrindo o arquivo binário no modo de escrita
    FILE *f = fopen("arquivo.txt", "w");

    //Verificando se foi possível abrir e escrever o arquivo
    if (f == NULL) {
        printf("Erro ao escrever o arquivo.\n");
        //Caso não seja possível abrir ou escrever o arquivo, retorna 1 encerrando a função
        return 0;
    }

    //Escrevendo a struct no arquivo
    fwrite(regs, sizeof(Registro), l->qtde, f);
    //Fechando o arquivo
    fclose(f);
    if(salvarDatas(l)){
        return 1;
    }
    else{
        return 0;
    }
}

int salvarDatas(Lista *l){

    Data datas[l->qtde];
    Elista *inicio = l->inicio;
    for(int i=0; i<l->qtde; i++){
        datas[i] = *inicio->dados->Entrada;
        inicio = inicio->proximo;
    }
    //Abrindo o arquivo binário no modo de escrita
    FILE *f = fopen("data.txt", "w");

    //Verificando se foi possível abrir e escrever o arquivo
    if (f == NULL) {
        printf("Erro ao escrever o arquivo datas.\n");
        //Caso não seja possível abrir ou escrever o arquivo, retorna 1 encerrando a função
        return 0;
    }

    //Escrevendo a struct no arquivo
    fwrite(datas, sizeof(Data), l->qtde, f);
    //Fechando o arquivo
    fclose(f);


    return 1;
};

int carregarDatas(Lista *l, ABB* arvIdade,ABB* arvAno,ABB* arvMes,ABB* arvDia){
    //Abrindo o arquivo binário no modo de leitura
    FILE *f = fopen("data.txt", "r");

    //Verificando se foi possível abrir e ler o arquivo
    if (f == NULL) {
        //Caso não seja possível abrir ou ler o arquivo, retorna 1 encerrando a função
        printf("Erro ao ler o arquivo data.\n");
        return 0;
    }

    //Variável para descobrir o número de clientes ja cadastrados presentes no arquivo
    int i = 0;
    Data datas[100];
    //Armazenando todas os clientes do arquivo em structs Cliente dentro da struct ListaDeClientes
    while (fread(&datas[i], sizeof(Data), 1, f) == 1) {
        //Iterando a quantidade de clientes
        i++;
    }

    Elista *inicio = l->inicio;
    int j = 0;
    while(inicio != NULL){
        inicio->dados->Entrada = &datas[j];
        insereABBGeral(arvIdade,arvAno,arvMes,arvDia, inicio->dados);
        inicio = inicio->proximo;
        j++;
    }

    //Armazenando o número de clientes
    l->qtde = i;

    //Fechando o arquivo
    fclose(f);
    return 1;
}

//Função para ler o arquivo binário e salvar as informações nas structs
int carregarRegistros(Lista *l, ABB* arvIdade,ABB* arvAno,ABB* arvMes,ABB* arvDia){
    //Abrindo o arquivo binário no modo de leitura
    FILE *f = fopen("arquivo.txt", "r");

    //Verificando se foi possível abrir e ler o arquivo
    if (f == NULL) {
        //Caso não seja possível abrir ou ler o arquivo, retorna 1 encerrando a função
        printf("Erro ao ler o arquivo.\n");
        return 0;
    }

    //Variável para descobrir o número de clientes ja cadastrados presentes no arquivo
    int i = 0;
    Registro regs[100];
    //Armazenando todas os clientes do arquivo em structs Cliente dentro da struct ListaDeClientes
    while (fread(&regs[i], sizeof(Registro), 1, f) == 1) {
        //Iterando a quantidade de clientes
        i++;
    }

    for(int j=0; j<i; j++){
        inserirLista(l, &regs[j]);
    }

    //Armazenando o número de clientes
    l->qtde = i;

    //Fechando o arquivo
    fclose(f);
    if(carregarDatas(l, arvIdade, arvAno, arvMes, arvDia)){
        return 1;
    }
    else{
        return 0;
    }
}

//--------------------------------------Funções de manipulação de arquivos--------------------------------------//


int menus(Lista *l, Fila *f, Pilha *p, ABB *arvi, ABB *arva, ABB *arvm, ABB *arvd) {
    int opcao;
    do {
        printf("Menu Principal:\n");
        printf("1. Lista de Pacientes\n");
        printf("2. Fila de espera\n");
        printf("3. Buscar por caracteristicas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        switch (opcao) {
            case 1:
                menuLista(l, arvi, arva, arvm, arvd);
                break;
            case 2:
                menuFila(l, f, p);
                break;
            case 3:
                menuArvore(l, arvi, arva, arvm, arvd);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
    return 0;
}

void menuLista(Lista *l, ABB *arvIdade, ABB *arvAno, ABB *arvMes, ABB *arvDia) {
    int opcao;
    char rg[20];
    do {
        printf("\nMenu de Manipulação de Lista:\n");
        printf("1. Cadastrar novo paciente\n");
        printf("2. Consultar paciente cadastrado\n");
        printf("3. Atualizar dados de paciente\n");
        printf("4. Remover paciente\n");
        printf("5. Mostrar lista de pacientes\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        switch (opcao) {
            case 1: {
                Registro *novoRegistro = criaRegistro();
                printf("\n");
                Cadastrar_novo_paciente(l, novoRegistro);
                insereABBGeral(arvIdade,arvAno,arvMes,arvDia, novoRegistro);
                break;
            }
            case 2:
                printf("\nDigite o RG do paciente: ");
                scanf("%s", rg);
                getchar(); // Limpar o buffer do teclado
                Consultar_paciente_cadastrado(l, rg);
                break;
            case 3:
                printf("\nDigite o RG do paciente: ");
                scanf("%s", rg);
                getchar(); // Limpar o buffer do teclado
                Atualizar_dados_de_paciente(l, rg, arvIdade,arvAno,arvMes,arvDia);
                break;
            case 4:
                printf("\nDigite o RG do paciente: ");
                scanf("%s", rg);
                getchar(); // Limpar o buffer do teclado
                Remover_paciente(l, rg, arvIdade,arvAno,arvMes,arvDia);
                break;
            case 5:
                printf("\n");
                showLista(l);
                break;
            case 0:
                printf("\nVoltando ao menu principal...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

void menuFila(Lista *l, Fila *f, Pilha *pilha) {
    int opcao;
    char rg[20];
    do {
        printf("\nMenu de Manipulação de Fila:\n");
        printf("1. Enfileirar paciente\n");
        printf("2. Desenfileirar paciente\n");
        printf("3. Mostrar fila de pacientes\n");
        printf("4. Desfazer ultima operacao\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        switch (opcao) {
            case 1:
                printf("\nDigite o RG do paciente: ");
                scanf("%s", rg);
                getchar(); // Limpar o buffer do teclado
                enqueueFila(f, l, rg, pilha);
                break;
            case 2:
                printf("\n");
                dequeueFila(f, pilha);
                break;
            case 3:
                printf("\n");
                showFila(f);
                break;
            case 4:
                printf("\n");
                desfazer(pilha,f);
                break;
            case 0:
                printf("\nVoltando ao menu principal...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}
void menuArvore(Lista *l, ABB *arvi, ABB *arva, ABB *arvm, ABB *arvd) {
    int opcao;
    do {
        printf("\nMenu de Manipulação de Árvore:\n");
        printf("1. Mostrar pacientes por idade\n");
        printf("2. Mostrar pacientes por ano\n");
        printf("3. Mostrar pacientes por mês\n");
        printf("4. Mostrar pacientes por dia\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        switch (opcao) {
            case 1:
                imprimeInOrdemABB(arvi->raiz);
                break;
            case 2:
                imprimeInOrdemABB(arva->raiz);
                break;
            case 3:
                imprimeInOrdemABB(arvm->raiz);
                break;
            case 4:
                imprimeInOrdemABB(arvd->raiz);
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}
