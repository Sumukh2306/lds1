#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *llink; // Left link (previous node)
    struct node *rlink; // Right link (next node)
};
typedef struct node *NODE;

// Function to create a new node
NODE getnode() {
    NODE x = (NODE)malloc(sizeof(struct node));
    if (x == NULL) {
        printf("Memory is full\n");
        exit(0);
    }
    return x;
}

// Insert at the rear
NODE insert_rear(NODE last, int item, int *count) {
    NODE temp = getnode();
    temp->info = item;
    temp->llink = temp->rlink = NULL;

    if (last == NULL) {
        // First node in the list
        temp->llink = temp->rlink = temp;
        *count = 1; // Update count for the first node
        return temp;
    }

    NODE first = last->rlink; // First node
    temp->rlink = first;
    temp->llink = last;
    last->rlink = temp;
    first->llink = temp;

    (*count)++;
    return temp;
}

// Make the last node point to the fifth node
NODE point_to_fifth(NODE last, int count) {
    if (count < 5) {
        printf("List has less than 5 nodes. Cannot set last node to point to the fifth node.\n");
        return last;
    }

    NODE fifth = last->rlink; // Start from the first node
    for (int i = 1; i < 5; i++) {
        fifth = fifth->rlink; // Move to the fifth node
    }

    last->rlink = fifth;
    printf("Last node now points to the fifth node with value: %d\n", fifth->info);
    return last;
}

// Display the list
void display(NODE last, int count) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    NODE cur = last->rlink; // Start from the first node
    printf("List: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", cur->info);
        cur = cur->rlink;
    }
    printf("\n");
}

// Main function
int main() {
    NODE last = NULL;
    int choice, item, count = 0;

    for (;;) {
        printf("\nMenu\n");
        printf("1. Insert at rear\n");
        printf("2. Point last node to the fifth node\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to insert at rear: ");
                scanf("%d", &item);
                last = insert_rear(last, item, &count);
                break;
            case 2:
                last = point_to_fifth(last, count);
                break;
            case 3:
                display(last, count);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
