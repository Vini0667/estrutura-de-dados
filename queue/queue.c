#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main (void) {
    struct Queue queue = {
        (int*)malloc(QUEUE_SIZE * sizeof(int)),
        INITIAL_VALUE_QUEUE
    };

    int i, menu, num, result;

    do {
        printf("O que você quer?\n");
        printf("0 - Sair\n1 - Adicionar um número\n2 - Retirar o número\n3 - Valor de end\n");
        scanf(" %d", &menu);

        switch (menu) {
            case 1:
                printf("Digite qual número que adicionar: ");
                scanf(" %d", &num);
                result = putAtTheEnd(&queue, num);
            break;

            case 2:
                result = unqueue(&queue);
                printf("Número retirado: %d\n\n", result);
            break;

            case 3:
                result = verifyEnd(&queue);
            break;

            default:
                break;
        }

        printf("\nResultado: %d\n\n", result);
            
        printf("Exibição da fila atual:\n\n");

        for (i = verifyEnd(&queue); i >= 0; i--) {
            printf("\n%d[%d]\n\n", queue.queue[i], i);
        }
    } while (menu != 0);
    

    return 0;
}