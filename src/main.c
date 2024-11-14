#include <stdio.h>
#include "bibliotecas/biblioteca.h"




int main() {
//----------------------------------------Criação das estruturas---------------------------------//
    
    Lista *lista = criaLista();
    Fila *fila = criaFila();
    Pilha *pilha = criaPilha();
    ABB *arvIdade = criaABB();
    ABB *arvAno = criaABB();
    ABB *arvMes = criaABB();
    ABB *arvDia = criaABB();

//----------------------------------------Criação das estruturas---------------------------------//

//----------------------------------------Carregamento de dados dos TXT---------------------------------//
    
    carregarRegistros(lista, arvIdade,arvAno,arvMes,arvDia);

//----------------------------------------Carregamento de dados dos TXT---------------------------------//

//----------------------------------------Menu Principal---------------------------------//
    menus(lista, fila, pilha, arvIdade, arvAno, arvMes, arvDia);
//----------------------------------------Menu Principal---------------------------------//
    return 0;
}
