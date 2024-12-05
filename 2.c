#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 20

struct stack {
    int top;
    char data[SIZE];
};
typedef struct stack STACK;

void push(STACK *s, char item) {
    if (s->top == SIZE - 1) {
        printf("\nStack Overflow\n");
        exit(1);
    }
    s->data[++(s->top)] = item;
}

char pop(STACK *s) {
    if (s->top == -1) {
        printf("\nStack Underflow\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

int preced(char symbol) {
    switch (symbol) {
        case '^': return 5;
        case '*':
        case '/': return 3;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

void infixtopostfix(STACK *s, char infix[SIZE]) {
    int i, j = 0;
    char postfix[SIZE], temp, symbol;

    for (i = 0; infix[i] != '\0'; i++) {
        symbol = infix[i];
        if (isalnum(symbol)) {
            postfix[j++] = symbol;
        } else {
            switch (symbol) {
                case '(':
                    push(s, symbol);
                    break;
                case ')':
                    temp = pop(s);
                    while (temp != '(') {
                        postfix[j++] = temp;
                        temp = pop(s);
                    }
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    while (s->top != -1 && s->data[s->top] != '(' && preced(s->data[s->top]) >= preced(symbol)) {
                        postfix[j++] = pop(s);
                    }
                    push(s, symbol);
                    break;
                default:
                    printf("\nInvalid character in the expression!\n");
                    exit(1);
            }
        }
    }
    while (s->top != -1) {
        postfix[j++] = pop(s);
    }
    postfix[j] = '\0';
    printf("\nThe postfix expression is: %s\n", postfix);
}

int main() {
    STACK s;
    s.top = -1;
    char infix[SIZE];
    printf("\nEnter an infix expression: ");
    scanf("%s", infix);
    infixtopostfix(&s, infix);
    return 0;
}
