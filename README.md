# Tetris Stack - Fila de Peças em C

Implementação de uma fila de peças do Tetris usando estrutura de dados Queue em linguagem C.

## Descrição

Este programa implementa um sistema de gerenciamento de peças do Tetris utilizando o conceito de fila (FIFO - First In, First Out). O usuário pode adicionar peças à fila, visualizá-las, removê-las e exibir estatísticas sobre as peças enfileiradas.

## Requisitos

- Compilador C (gcc, clang, ou similar)
- Sistema operacional compatível com POSIX (Linux, macOS) ou Windows
- Terminal/Console para execução

## Compilação

```bash
gcc tetris_fila.c -o tetris_fila
```

Ou no Windows:
```cmd
gcc tetris_fila.c -o tetris_fila.exe
```

## Execução

```bash
./tetris_fila
```

Ou no Windows:
```cmd
tetris_fila.exe
```

## Menu de Opções

O programa apresenta um menu interativo com as seguintes opções:

1. **Adicionar peça** - Insere uma nova peça do Tetris na fila
2. **Remover peça** - Remove a primeira peça da fila (seguindo a ordem FIFO)
3. **Visualizar fila** - Exibe todas as peças atualmente na fila
4. **Exibir estatísticas** - Mostra estatísticas sobre as peças na fila
5. **Sair** - Encerra o programa

## Tipos de Peças

O programa reconhece 7 tipos de peças do Tetris:

- **I** - Peça em forma de barra (4 blocos em linha)
- **O** - Peça em forma de quadrado (2x2)
- **T** - Peça em forma de T
- **S** - Peça em forma de S
- **Z** - Peça em forma de Z
- **J** - Peça em forma de J
- **L** - Peça em forma de L

## Funcionamento Básico

### Estrutura de Dados

O programa utiliza uma estrutura de fila encadeada (linked queue) onde:
- Cada nó contém uma peça do Tetris
- A fila mantém ponteiros para o início (front) e fim (rear)
- Operações de inserção ocorrem no fim da fila
- Operações de remoção ocorrem no início da fila

### Operações Principais

1. **Enfileirar (Enqueue)**: Adiciona uma nova peça ao final da fila
2. **Desenfileirar (Dequeue)**: Remove a peça do início da fila
3. **Visualização**: Percorre toda a fila exibindo as peças
4. **Estatísticas**: Calcula e exibe a quantidade de cada tipo de peça

## Instruções Rápidas de Uso

1. Execute o programa
2. Escolha a opção **1** para adicionar peças
3. Digite o tipo da peça (I, O, T, S, Z, J ou L)
4. Repita o processo para adicionar mais peças
5. Use a opção **3** para visualizar as peças na fila
6. Use a opção **4** para ver estatísticas
7. Use a opção **2** para remover peças (sempre remove a primeira da fila)
8. Use a opção **5** para sair

## Exemplo de Uso

```
=== TETRIS STACK - FILA DE PEÇAS ===
1. Adicionar peça
2. Remover peça
3. Visualizar fila
4. Exibir estatísticas
5. Sair
Escolha uma opção: 1

Digite o tipo da peça (I, O, T, S, Z, J, L): T
Peça T adicionada à fila!

Escolha uma opção: 3
Fila de peças: T
```

## Características

- Gerenciamento dinâmico de memória
- Interface interativa em linha de comando
- Validação de entrada de dados
- Sistema de estatísticas para análise das peças
- Implementação clara e didática do conceito de fila

## Autor

Desenvolvido como material didático para estudo de estruturas de dados.

## Licença

Este projeto é de código aberto e está disponível para fins educacionais.
