#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define the maximum size of the queue

// Circular Queue structure
struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

// Function to initialize the queue
void initQueue(struct Queue *q) {
    q->front = -1;  // Queue is initially empty
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(struct Queue *q) {
    return (q->rear + 1) % MAX == q->front;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *q) {
    return q->front == -1;
}

// Function to enqueue (insert) an element into the queue
void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
    } else {
        if (q->front == -1) {  // If queue is empty, set front to 0
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX;  // Increment rear circularly
        q->arr[q->rear] = value;  // Insert the value
        printf("Enqueued %d into the queue\n", value);
    }
}

// Function to dequeue (remove) an element from the queue
int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;  // Return an invalid value for underflow
    } else {
        int dequeuedValue = q->arr[q->front];
        if (q->front == q->rear) {  // If only one element exists, reset queue
            q->front = q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX;  // Increment front circularly
        }
        return dequeuedValue;
    }
}

// Function to peek the front element of the queue
int peek(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;  // Return an invalid value for empty queue
    } else {
        return q->arr[q->front];  // Return the front element
    }
}

// Function to display the queue elements
void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are:\n");
        int i = q->front;
        while (i != q->rear) {
            printf("%d ", q->arr[i]);
            i = (i + 1) % MAX;  // Circular increment
        }
        printf("%d\n", q->arr[q->rear]);  // Print the last element
    }
}

// Main function to test the queue implementation
int main() {
    struct Queue q;
    int choice, value;

    initQueue(&q);  // Initialize the queue

    while (1) {
        printf("\nCircular Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("Dequeued %d from the queue\n", value);
                }
                break;
            case 3:
                value = peek(&q);
                if (value != -1) {
                    printf("Front element is %d\n", value);
                }
                break;
            case 4:
                display(&q);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
