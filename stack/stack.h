#ifndef STACK_H // Verifica se STACK_H esta definido
#define STACK_H // Caso não esteja o compilador o define nesta linha

// Define as constantes dos códigos

const int STACK_SIZE = 5;
const int INITIAL_VALUE_TOP = -1;
const int ERROR_STACK_IS_EMPTY = -2;
const int ERROR_STACK_IS_FULL = -3;
const int SUCCESS_OPERATION = 0;

struct Stack { // Define nossa Stack
    int *stack;
    int top;
};

int putOnTop(struct Stack* stack, int data); // Header das funções implementadas abaixo
int unstack(struct Stack* stack);
int verifyTop (struct Stack stack);
int verifyStackIsFull (struct Stack stack);
int verifyStackIsVoid (struct Stack stack); // Aqui é somente uma inicialização

#endif // Fecha a verificação aberta acima, caso STACK_H esteja definido ao chamar a biblioteca o código acima é ignorado

#include <stdlib.h> // Não sei se devo invocar stdlib.h aqui, pois já a invoco na main, porém por via das dúvidas a invoquei (não sei se é uma boa prática)

extern inline int verifyStackIsFull (struct Stack stack) { // Ver depois o funcionamento do `inline`, pois ainda gera dúvidas
    if (stack.top == STACK_SIZE - 1) {
        return ERROR_STACK_IS_FULL;
    } else {
        return SUCCESS_OPERATION;
    }
}

extern inline int verifyStackIsEmpty (struct Stack stack) {
    if (stack.top == INITIAL_VALUE_TOP) {
        return ERROR_STACK_IS_EMPTY;
    } else {
        return SUCCESS_OPERATION;
    }
}

extern inline int verifyTop (struct Stack stack) {
    return stack.top;
}

// Obs: Achei desnecessário passar por ponteiro as funções de verificação,
// pois mesmo que gaste mais processamento copiar os arquivos da stack para outra acredito que não seja
// tão necessário passar por ponteiro para uma função simples.

// Novamente posso estar completamente enganado e vou estar pesquisando mais sobre. 

// Abaixo estão as funções de empilhar e desempilhar, ambas bem simples

extern inline int putAtTheTop (struct Stack* stack, int data) {
    if (verifyStackIsFull(*stack) == ERROR_STACK_IS_FULL) {
        return ERROR_STACK_IS_FULL;
    } else {
        stack->top++;
        stack->stack[stack->top] = data;
        return SUCCESS_OPERATION;
    }
}

extern inline int unstack (struct Stack* stack) {
    if (verifyStackIsEmpty(*stack) == ERROR_STACK_IS_EMPTY) {
        return ERROR_STACK_IS_EMPTY;
    } else { 
        int result = stack->stack[stack->top];
        stack->stack[stack->top] = 0;
        stack->top--;
        return result;
    }
}