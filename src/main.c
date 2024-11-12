#include <stdio.h>
#include "bibliotecas/biblioteca.h"




int main() {
    //Somente para testes da lista//
    Lista *lista = criaLista();
    Fila *fila = criaFila();
    Pilha *pilha = criaPilha();
    carregarRegistros(lista);
    ABB *arvIdade = criaABB();
    ABB *arvAno = criaABB();
    ABB *arvMes = criaABB();
    ABB *arvDia = criaABB();


    menus(lista, fila, pilha, arvIdade, arvAno, arvMes, arvDia);
    return 0;
}
