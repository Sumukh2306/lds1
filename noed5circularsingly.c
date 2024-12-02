#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* link;
};
typedef struct node* NODE;

// Function to create a new node
NODE getnode() {
    NODE x = (NODE)malloc(sizeof(struct node));
    if (x == NULL) {
        printf("Memory is full\n");
        exit(0);
    }
    return x;
}

// Insert at the rear of the list
NODE insert_rear(NODE last, int item, int* count) {
    NODE temp = getnode();
    temp->info = item;
    temp->link = NULL;

    (*count)++;  // Increment the node count

    if (last == NULL) {
        temp->link = temp;  // If list is empty, point to itself
        return temp;
    }

    temp->link = last->link;  // Insert after last node
    last->link = temp;
    return temp;  // Return the new last node
}

// Adjust the last node to point to the 5th node
NODE adjust_last_to_fifth(NODE last, int count) {
    if (last == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (count < 5) {
        printf("Less than 5 nodes. Cannot adjust last node to point to the 5th node.\n");
        return last;
    }

    NODE fifth = last->link;  // Start from the first node
    for (int i = 1; i < 5; i++) {
        fifth = fifth->link;  // Traverse to the 5th node
    }

    last->link = fifth;  // Point last node to the 5th node
    printf("Last node now points to the 5th node with value: %d\n", fifth->info);
    return last;
}

// Display the list to visualize the structure
void display(NODE last, int count) {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    NODE cur = last->link;  // Start from the first node
    int steps = count + 5;  // To prevent infinite loop, limit traversal

    printf("List: ");
    while (steps-- > 0) {
        printf("%d ", cur->info);
        cur = cur->link;
        if (cur == last->link)  // Back to the start
            break;
    }
    printf("\n");
}

// Main function
int main() {
    NODE last = NULL;
    int count = 0, choice, item;

    for (;;) {
        printf("\nMenu\n");
        printf("1. Insert at rear\n");
        printf("2. Adjust last node to point to the 5th node\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &item);
                last = insert_rear(last, item, &count);
                break;
            case 2:
                last = adjust_last_to_fifth(last, count);
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
