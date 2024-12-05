#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct queue {
    int front, rear;
    char data[SIZE];
};
typedef struct queue QUEUE;

void enqueue(QUEUE *q, char item) {
    if (q->rear == SIZE - 1) {
        printf("\nQueue full\n");
    } else {
        q->rear = q->rear + 1;
        q->data[q->rear] = item;
        if (q->front == -1) {
            q->front = 0;
        }
        printf("\n'%c' inserted into the queue\n", item);
    }
}

char dequeue(QUEUE *q) {
    char del;
    if (q->front == -1) {
        printf("\nQueue empty\n");
        return -1;
    } else {
        del = q->data[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = q->front + 1;
        }
        return del;
    }
}

void display(QUEUE q) {
    int i;
    if (q.front == -1) {
        printf("\nQueue is empty\n");
    } else {
        printf("\nQueue contents are:\n");
        for (i = q.front; i <= q.rear; i++) {
            printf("%c\t", q.data[i]);
        }
        printf("\n");
    }
}

int main() {
    char item, del;
    int ch;
    QUEUE q;
    q.front = -1;
    q.rear = -1;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        getchar(); // To handle the newline character left in the buffer

        switch (ch) {
            case 1:
                printf("\nEnter the element to be inserted: ");
                scanf("%c", &item);
                enqueue(&q, item);
                break;
            case 2:
                del = dequeue(&q);
                if (del != -1) {
                    printf("\nElement deleted is '%c'\n", del);
                }
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("\nExiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please select a valid option.\n");
        }
    }
    return 0;
}
