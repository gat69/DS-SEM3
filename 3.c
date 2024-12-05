#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define SIZE 20

struct stack {
    int top;
    float data[SIZE];
};
typedef struct stack STACK;

void push(STACK *s, float item) {
    if (s->top == SIZE - 1) {
        printf("\nStack Overflow\n");
        exit(1);
    }
    s->data[++(s->top)] = item;
}

float pop(STACK *s) {
    if (s->top == -1) {
        printf("\nStack Underflow\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

float operate(float op1, float op2, char symbol) {
    switch (symbol) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': 
            if (op2 == 0) {
                printf("\nDivision by zero error!\n");
                exit(1);
            }
            return op1 / op2;
        case '^': return pow(op1, op2);
        default:
            printf("\nInvalid operator: %c\n", symbol);
            exit(1);
    }
}

float eval(STACK *s, char postfix[SIZE]) {
    int i;
    char symbol;
    float res, op1, op2;

    for (i = 0; postfix[i] != '\0'; i++) {
        symbol = postfix[i];
        if (isdigit(symbol)) {
            push(s, symbol - '0');  // Convert char digit to float
        } else {
            op2 = pop(s);
            op1 = pop(s);
            res = operate(op1, op2, symbol);
            push(s, res);
        }
    }
    return pop(s);
}

int main() {
    char postfix[SIZE];
    STACK s;
    float ans;
    s.top = -1;

    printf("\nEnter a postfix expression: ");
    scanf("%s", postfix);

    ans = eval(&s, postfix);
    printf("\nThe final answer is: %.2f\n", ans);

    return 0;
}
