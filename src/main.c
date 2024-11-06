#include <stdio.h>
#include "bibliotecas/biblioteca.h"




int main() {
    //Somente para testes da lista//
    Lista *lista = criaLista();
    ABB *arvIdade = criaABB();
    int opcao;
    char rg[10];

    do {
        printf("\nMenu:\n");
        printf("1 - Cadastrar novo paciente\n");
        printf("2 - Mostrar todos os pacientes\n");
        printf("3 - Encontrar paciente pelo RG\n");
        printf("4 - Atualizar dados do paciente\n");
        printf("5 - Remover paciente\n");
        printf("6 - Mostrar pacientes por idade\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o '\n' do buffer de entrada

        switch(opcao) {
            case 1: {
                Registro *novoRegistro = criaRegistro();
                inserirLista(lista, novoRegistro);
                insereABBGeral(arvIdade, novoRegistro);
                printf("Paciente cadastrado com sucesso!\n");
                break;
            }
            case 2:
                printf("\nLista de Pacientes:\n");
                showLista(lista);
                break;
            case 3:
                printf("Digite o RG do paciente que deseja encontrar: ");
                scanf("%s", rg);
                getchar(); // Limpa o '\n' do buffer de entrada
                Consultar_paciente_cadastrado(lista, rg);
                break;
            case 4:
                printf("Digite o RG do paciente que deseja atualizar: ");
                scanf("%s", rg);
                getchar(); // Limpa o '\n' do buffer de entrada
                Atualizar_dados_de_paciente(lista, rg);
                break;
            case 5:
                printf("Digite o RG do paciente que deseja apagar: ");
                scanf("%s", rg);
                getchar(); // Limpa o '\n' do buffer de entrada
                Remover_paciente(lista, rg);
                removeABBGeral(arvIdade, rg);
                break;
            case 6:
                printf("\nLista de Pacientes:\n");
                imprimeInOrdemABB(arvIdade->raiz);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while(opcao != 0);

    return 0;
}
