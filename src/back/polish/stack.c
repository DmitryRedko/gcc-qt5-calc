#include "stack.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "tokenize.h"

Stack *create_stack(int size) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->items = (Token *)malloc(sizeof(Token) * size);
    stack->size = size;
    stack->top = -1;
    return stack;
}

void push(Stack *stack, Token item) {
    if (!is_full(stack)) {
        stack->top++;
        stack->items[stack->top] = item;
    }
}

Token pop(Stack *stack) {
    Token item;
    item.type = TOK_END;
    if (!is_empty(stack)) {
        item = stack->items[stack->top];
        stack->top--;
    }
    return item;
}

int is_empty(Stack *stack) { return (stack->top == -1); }

int is_full(Stack *stack) { return (stack->top == stack->size - 1); }

void free_stack(Stack *stack) {
    free_tokens(stack->items);
    free(stack);
}


void print_stack(Stack *stack) {
    for (int i = 0; i <= stack->top; i++) {
        Token item = stack->items[i];
        if (item.type == TOK_NUMBER) {
            printf("Number: %lf\n", item.value);
        } else if (item.type == TOK_OP_PLUS) {
            printf("Operator: +\n");
        } else if (item.type == TOK_OP_MINUS) {
            printf("Operator: -\n");
        } else if (item.type == TOK_OP_MULT) {
            printf("Operator: *\n");
        } else if (item.type == TOK_OP_DIV) {
            printf("Operator: /\n");
        } else if (item.type == TOK_FUNC_SIN) {
            printf("Function: sin\n");
        } else if (item.type == TOK_FUNC_COS) {
            printf("Function: cos\n");
        } else if (item.type == TOK_FUNC_TG) {
            printf("Function: tg\n");
        } else if (item.type == TOK_FUNC_LN) {
            printf("Function: ln\n");
        } else if (item.type == TOK_FUNC_SQRT) {
            printf("Function: sqrt\n");
        } else if (item.type == TOK_RPAREN) {
            printf("Function: )\n");
        } else if (item.type == TOK_LPAREN) {
            printf("Function: (\n");
        } else if (item.type == TOK_VARIABLE) {
            printf("Variable: %c\n", (char)item.value); // Assuming you use a char value for variables
        }
    }
}
