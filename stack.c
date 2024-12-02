#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define the maximum size of the stack

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack *stack) {
    stack->top = -1;  // Stack is initially empty
}

// Function to check if the stack is full
int isFull(struct Stack *stack) {
    return stack->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
    } else {
        stack->arr[++(stack->top)] = value;  // Increment top and insert the value
        printf("Pushed %d onto the stack\n", value);
    }
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;  // Return an invalid value for underflow
    } else {
        int poppedValue = stack->arr[(stack->top)--];  // Decrement top and return the value
        return poppedValue;
    }
}

// Function to peek the top element of the stack
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;  // Return an invalid value for empty stack
    } else {
        return stack->arr[stack->top];  // Return the top element
    }
}

// Function to display the stack elements
void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}

// Main function to test the stack implementation
int main() {
    struct Stack stack;
    int choice, value;

    initStack(&stack);  // Initialize the stack

    while (1) {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("Popped %d from the stack\n", value);
                }
                break;
            case 3:
                value = peek(&stack);
                if (value != -1) {
                    printf("Top element is %d\n", value);
                }
                break;
            case 4:
                display(&stack);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
