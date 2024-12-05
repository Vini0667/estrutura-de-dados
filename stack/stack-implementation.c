#include <stdio.h>
#include <stdlib.h> // Este código esta duplicado, comentei no stack.h
#include </home/vini/Documents/data-structure/stack/stack.h> // Importa a biblioteca (COLOCAR O CAMINHO COMPLETO DO SEU PC)
// Ainda sobre a biblioteca, não sei como posso invoca-la igual as acima
// Muito provavelmente transferindo a mesma para a pasta de bibliotecas C, mas para esse exemplo basta.

int main (void) {
    struct Stack stack = {
        (int*)malloc(STACK_SIZE * sizeof(int)), // Calcula o tamanho de memória a ser alocado para os números definidos em STACK_SIZE e faz um cast para inteiro
        MIN_VALUE_TOP
    };

    int menu = 1, i, result, random_number;

    while (menu != 0) {
        printf("O que você quer?\n");
        printf("0 - Sair\n1 - Adicionar um número\n2 - Retirar o número\n3 - Valor de top\n");
        scanf(" %i", &menu);

        switch (menu) { // Usei um simples Switch case, de condicional com o que o usuário quer fazer
            case 1:
                printf("Digite o número que quer adicionar ao topo: ");
                scanf(" %i", &random_number);
                result = putOnTop(&stack, random_number); // Lembrar do & para passar a posição da memória da variável e não o conteúdo.
            break;

            case 2:
                result = unstack(&stack);
                printf("\nNúmero retirado: %i\n\n", result);
            break;
            
            case 3:
                result = verifyTop(stack);
                printf("\nValor da variável Top: %i\n\n", result);
            break;

            default:
                break;
        }

        printf("\nEstado da Stack:\n\n");

        for (i = 0; i < STACK_SIZE; i++) {
            printf("%i\n", stack.stack[i]); // Aqui só mostra como é o estado da Stack
        }
        printf("\n"); // Ignore, é somente para pular mais uma linha mesmo
    }

    return 0;
}