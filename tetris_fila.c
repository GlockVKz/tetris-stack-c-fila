#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Estrutura para representar uma peça do Tetris
typedef struct Peca {
    char tipo;  // I, O, T, S, Z, J, L
    struct Peca* proxima;
} Peca;

// Estrutura para representar a fila
typedef struct {
    Peca* inicio;
    Peca* fim;
    int tamanho;
} Fila;

// Função para criar uma nova fila vazia
Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
    return fila;
}

// Função para verificar se a fila está vazia
int filaVazia(Fila* fila) {
    return fila->inicio == NULL;
}

// Função para adicionar uma peça à fila (enqueue)
void adicionarPeca(Fila* fila, char tipo) {
    // Validar o tipo de peça
    tipo = toupper(tipo);
    if (tipo != 'I' && tipo != 'O' && tipo != 'T' && 
        tipo != 'S' && tipo != 'Z' && tipo != 'J' && tipo != 'L') {
        printf("\nTipo de pe\u00e7a inv\u00e1lido! Use I, O, T, S, Z, J ou L.\n");
        return;
    }
    
    Peca* novaPeca = (Peca*)malloc(sizeof(Peca));
    novaPeca->tipo = tipo;
    novaPeca->proxima = NULL;
    
    if (filaVazia(fila)) {
        fila->inicio = novaPeca;
        fila->fim = novaPeca;
    } else {
        fila->fim->proxima = novaPeca;
        fila->fim = novaPeca;
    }
    
    fila->tamanho++;
    printf("\nPe\u00e7a %c adicionada \u00e0 fila!\n", tipo);
}

// Função para remover uma peça da fila (dequeue)
char removerPeca(Fila* fila) {
    if (filaVazia(fila)) {
        printf("\nFila vazia! N\u00e3o h\u00e1 pe\u00e7as para remover.\n");
        return '\0';
    }
    
    Peca* pecaRemovida = fila->inicio;
    char tipo = pecaRemovida->tipo;
    
    fila->inicio = fila->inicio->proxima;
    
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    
    free(pecaRemovida);
    fila->tamanho--;
    
    printf("\nPe\u00e7a %c removida da fila!\n", tipo);
    return tipo;
}

// Função para visualizar todas as peças na fila
void visualizarFila(Fila* fila) {
    if (filaVazia(fila)) {
        printf("\nFila vazia!\n");
        return;
    }
    
    printf("\nFila de pe\u00e7as (%d pe\u00e7as): ", fila->tamanho);
    Peca* atual = fila->inicio;
    while (atual != NULL) {
        printf("%c ", atual->tipo);
        atual = atual->proxima;
    }
    printf("\n");
}

// Função para exibir estatísticas das peças na fila
void exibirEstatisticas(Fila* fila) {
    if (filaVazia(fila)) {
        printf("\nFila vazia! Sem estat\u00edsticas para exibir.\n");
        return;
    }
    
    int contadores[7] = {0}; // I, O, T, S, Z, J, L
    Peca* atual = fila->inicio;
    
    while (atual != NULL) {
        switch (atual->tipo) {
            case 'I': contadores[0]++; break;
            case 'O': contadores[1]++; break;
            case 'T': contadores[2]++; break;
            case 'S': contadores[3]++; break;
            case 'Z': contadores[4]++; break;
            case 'J': contadores[5]++; break;
            case 'L': contadores[6]++; break;
        }
        atual = atual->proxima;
    }
    
    printf("\n=== ESTAT\u00cdSTICAS DA FILA ===\n");
    printf("Total de pe\u00e7as: %d\n", fila->tamanho);
    printf("\nQuantidade por tipo:\n");
    printf("Pe\u00e7a I: %d\n", contadores[0]);
    printf("Pe\u00e7a O: %d\n", contadores[1]);
    printf("Pe\u00e7a T: %d\n", contadores[2]);
    printf("Pe\u00e7a S: %d\n", contadores[3]);
    printf("Pe\u00e7a Z: %d\n", contadores[4]);
    printf("Pe\u00e7a J: %d\n", contadores[5]);
    printf("Pe\u00e7a L: %d\n", contadores[6]);
}

// Função para limpar a memória da fila
void liberarFila(Fila* fila) {
    while (!filaVazia(fila)) {
        removerPeca(fila);
    }
    free(fila);
}

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para exibir o menu
void exibirMenu() {
    printf("\n=== TETRIS STACK - FILA DE PE\u00c7AS ===\n");
    printf("1. Adicionar pe\u00e7a\n");
    printf("2. Remover pe\u00e7a\n");
    printf("3. Visualizar fila\n");
    printf("4. Exibir estat\u00edsticas\n");
    printf("5. Sair\n");
    printf("\nEscolha uma op\u00e7\u00e3o: ");
}

// Função principal
int main() {
    Fila* fila = criarFila();
    int opcao;
    char tipo;
    
    printf("\n************************************\n");
    printf("*   BEM-VINDO AO TETRIS STACK!     *\n");
    printf("*   Sistema de Fila de Pe\u00e7as      *\n");
    printf("************************************\n");
    
    while (1) {
        exibirMenu();
        
        if (scanf("%d", &opcao) != 1) {
            limparBuffer();
            printf("\nOp\u00e7\u00e3o inv\u00e1lida! Digite um n\u00famero.\n");
            continue;
        }
        limparBuffer();
        
        switch (opcao) {
            case 1:
                printf("\nDigite o tipo da pe\u00e7a (I, O, T, S, Z, J, L): ");
                scanf("%c", &tipo);
                limparBuffer();
                adicionarPeca(fila, tipo);
                break;
                
            case 2:
                removerPeca(fila);
                break;
                
            case 3:
                visualizarFila(fila);
                break;
                
            case 4:
                exibirEstatisticas(fila);
                break;
                
            case 5:
                printf("\nEncerrando o programa...\n");
                printf("Pe\u00e7as na fila ao sair: %d\n", fila->tamanho);
                liberarFila(fila);
                printf("\nObrigado por usar o Tetris Stack!\n");
                return 0;
                
            default:
                printf("\nOp\u00e7\u00e3o inv\u00e1lida! Tente novamente.\n");
        }
    }
    
    return 0;
}
