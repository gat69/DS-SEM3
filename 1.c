#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct stack {
    int top;
    int data[SIZE];
};

typedef struct stack STACK;

// Function to push an element onto the stack
void push(STACK *s, int item) {
    if (s->top == SIZE - 1) {
        printf("\nStack Overflow. Cannot push %d.\n", item);
    } else {
        s->top = s->top + 1;
        s->data[s->top] = item;
        printf("\n%d pushed onto the stack.\n", item);
    }
}

// Function to pop an element from the stack
void pop(STACK *s) {
    if (s->top == -1) {
        printf("\nStack Underflow. Cannot pop.\n");
    } else {
        printf("\nElement popped: %d\n", s->data[s->top]);
        s->top = s->top - 1;
    }
}

// Function to display stack contents
void display(STACK *s) {
    if (s->top == -1) {
        printf("\nStack is empty.\n");
    } else {
        printf("\nStack contents are:\n");
        for (int i = s->top; i >= 0; i--) {
            printf("%d\n", s->data[i]);
        }
    }
}

// Main function to provide a menu-driven interface
int main() {
    int ch, item;
    STACK s;
    s.top = -1;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter the element to push: ");
                scanf("%d", &item);
                push(&s, item);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                display(&s);
                break;
            case 4:
                printf("\nExiting program. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}
