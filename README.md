# Projeto de Sistema de Gestão de Pacientes

Este projeto implementa um sistema de gerenciamento de dados de pacientes em **C**, com funcionalidades para cadastro, consulta, atualização e remoção de informações. O sistema utiliza diferentes estruturas de dados, como **listas**, **filas**, **pilhas** e **árvores binárias balanceadas (ABB)**, para organizar os dados de pacientes de forma eficiente.

## Funcionalidades e Estruturas de Dados

### Estruturas Principais

- **Lista Duplamente Encadeada**: Utilizada para armazenar e manipular dados de pacientes.
- **Fila e Pilha**: Aplicadas para operações de espera e navegação de histórico de ações no sistema.
- **Árvore Binária Balanceada (ABB)**: Implementada para organizar e realizar buscas eficientes dos registros de pacientes, principalmente pelo número de identificação.

### Funcionalidades

1. **Cadastro de Paciente**: Adiciona um novo paciente ao sistema. Os dados armazenados incluem nome, idade, histórico médico e número de identificação.
2. **Consulta de Pacientes**: Permite buscar e exibir dados de um paciente específico usando o número de identificação.
3. **Atualização de Dados**: Altera as informações de um paciente já cadastrado no sistema.
4. **Remoção de Paciente**: Exclui um paciente do sistema com base em seu número de identificação.
5. **Histórico e Fila de Espera**: Armazena as ações dos usuários e gerencia uma lista de espera para pacientes.
6. **Filtrar por Data**: Mostra todos os pacientes de acordo com a informação desejada(Idade, dia, mês, ano).

## Organização do Código

### Estrutura do Projeto

- `main.c`: Contém a Criação da lista, fila, pilha e arvores e chama a função de inicio do código.
- `biblioteca.c` e `biblioteca.h`: Contém todas as funções e estruturas utilizadas no código.

### Estruturas de Dados e Funções

#### Lista Duplamente Encadeada

A lista duplamente encadeada é usada para armazenar os pacientes de forma ordenada. As principais funções incluem:

- `inserir_paciente`: Insere um novo paciente na lista.
- `remover_paciente`: Remove um paciente especificado pela ID.
- `atualizar_paciente`: Atualiza os dados de um paciente.

#### Árvore Binária Balanceada (ABB)

A árvore é usada para buscar pacientes rapidamente. Principais funções:

- `inserir_na_abb`: Insere um paciente na árvore, organizando-o por número de identificação.
- `buscar_na_abb`: Busca um paciente pela ID.
- `remover_da_abb`: Remove um paciente da árvore com base na ID.

#### Fila e Pilha

Implementadas para gerenciar o histórico de ações e a fila de espera. Principais funções:

- `inserir_fila`: Adiciona uma nova ação à fila.
- `remover_fila`: Remove a ação mais antiga da fila.
- `empilhar`: Armazena uma ação na pilha.
- `desempilhar`: Remove a ação mais recente da pilha.

## Como Executar o Projeto

1. Clone o repositório para sua máquina local:
    ```bash
    git clone https://github.com/seu-usuario/sistema-gestao-pacientes.git
    cd sistema-gestao-pacientes
    ```

2. Compile o projeto usando `make` (ou diretamente com `gcc`, se preferir):
    ```bash
    make
    ```

3. Execute o sistema:
    ```bash
    ./sistema_pacientes
    ```

## Estrutura do Menu

O sistema apresenta um menu principal que chama submenus para cada funcionalidade e estrutura de dados:

1. **Menu de Pacientes**:
   - `1. Cadastrar Paciente`
   - `2. Consultar Paciente`
   - `3. Atualizar Dados`
   - `4. Mostrar todos pacientes`
   - `5. Remover Paciente`

2. **Menu de Fila e Pilha**:
   - `1. Adicionar à Fila`
   - `2. Remover da Fila`
   - `3. Mostrar a fila inteira`
   - `4. Exibir Histórico (Pilha)`
   - `5. Desfazer a ultima ação da fila`

3. **Menu de Árvore Binária (ABB)**:
   - `1. Buscar por idade`
   - `2. Buscar por dia`
   - `3. Busca por mês`
   - `4. Busca por ano`
## Criadores

Pedro Henrique Satoru LimaTakahashi

Pedro Henrqiue Correia de Oliveira

