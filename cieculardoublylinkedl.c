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

// Insert at the front
NODE insert_front(NODE last, int item) {
    NODE temp = getnode();
    temp->info = item;

    if (last == NULL) {
        // If the list is empty
        temp->llink = temp->rlink = temp;
        return temp;
    }

    NODE first = last->rlink; // First node
    temp->rlink = first;
    temp->llink = last;
    first->llink = temp;
    last->rlink = temp;

    return last; // Last remains unchanged
}

// Insert at the rear
NODE insert_rear(NODE last, int item) {
    NODE temp = getnode();
    temp->info = item;

    if (last == NULL) {
        // If the list is empty
        temp->llink = temp->rlink = temp;
        return temp;
    }

    NODE first = last->rlink; // First node
    temp->rlink = first;
    temp->llink = last;
    last->rlink = temp;
    first->llink = temp;

    return temp; // Update last to the newly added node
}

// Delete from the front
NODE delete_front(NODE last) {
    if (last == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    NODE first = last->rlink; // First node
    if (first == last) {
        // Only one node in the list
        printf("The item deleted is %d\n", first->info);
        free(first);
        return NULL;
    }

    NODE second = first->rlink; // Second node
    printf("The item deleted is %d\n", first->info);
    last->rlink = second;
    second->llink = last;
    free(first);

    return last;
}

// Delete from the rear
NODE delete_rear(NODE last) {
    if (last == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    if (last->rlink == last) {
        // Only one node in the list
        printf("The item deleted is %d\n", last->info);
        free(last);
        return NULL;
    }

    NODE first = last->rlink; // First node
    NODE prev = last->llink;  // Second-to-last node
    printf("The item deleted is %d\n", last->info);
    prev->rlink = first;
    first->llink = prev;
    free(last);

    return prev; // Update last to the new last node
}

// Display the elements in the list
void display(NODE last) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    NODE cur = last->rlink; // Start from the first node
    printf("List: ");
    do {
        printf("%d ", cur->info);
        cur = cur->rlink;
    } while (cur != last->rlink); // Loop until we return to the first node
    printf("\n");
}

// Search for a key in the list
void search(NODE last, int key) {
    if (last == NULL) {
        printf("List is empty. Key not found.\n");
        return;
    }

    NODE cur = last->rlink; // Start from the first node
    do {
        if (cur->info == key) {
            printf("Key found: %d\n", key);
            return;
        }
        cur = cur->rlink;
    } while (cur != last->rlink); // Loop until we return to the first node

    printf("Key not found: %d\n", key);
}

// Main function
int main() {
    NODE last = NULL;
    int choice, item, key;

    for (;;) {
        printf("\nMenu\n");
        printf("1. Insert at front\n");
        printf("2. Insert at rear\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Display\n");
        printf("6. Search\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to insert at front: ");
                scanf("%d", &item);
                last = insert_front(last, item);
                break;
            case 2:
                printf("Enter the item to insert at rear: ");
                scanf("%d", &item);
                last = insert_rear(last, item);
                break;
            case 3:
                last = delete_front(last);
                break;
            case 4:
                last = delete_rear(last);
                break;
            case 5:
                display(last);
                break;
            case 6:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                search(last, key);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
