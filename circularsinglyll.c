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

// Insert at the front of the circular linked list
NODE insert_front(NODE last, int item) {
    NODE temp = getnode();
    temp->info = item;
    if (last == NULL) {  // If the list is empty
        temp->link = temp;
        return temp;
    }
    temp->link = last->link;
    last->link = temp;
    return last;
}

// Insert at the rear of the circular linked list
NODE insert_rear(NODE last, int item) {
    NODE temp = getnode();
    temp->info = item;
    if (last == NULL) {  // If the list is empty
        temp->link = temp;
        return temp;
    }
    temp->link = last->link;
    last->link = temp;
    return temp;  // Return new last node
}

// Delete from the front of the circular linked list
NODE delete_front(NODE last) {
    if (last == NULL) {  // If the list is empty
        printf("List is empty\n");
        return NULL;
    }
    NODE first = last->link;
    if (last == first) {  // If there is only one node
        printf("The item deleted is %d\n", first->info);
        free(first);
        return NULL;
    }
    last->link = first->link;
    printf("The item deleted is %d\n", first->info);
    free(first);
    return last;
}

// Delete from the rear of the circular linked list
NODE delete_rear(NODE last) {
    if (last == NULL) {  // If the list is empty
        printf("List is empty\n");
        return NULL;
    }
    NODE cur = last->link, prev = NULL;
    if (cur == last) {  // If there is only one node
        printf("The item deleted is %d\n", last->info);
        free(last);
        return NULL;
    }
    while (cur->link != last->link) {  // Traverse to the last node
        prev = cur;
        cur = cur->link;
    }
    prev->link = last->link;
    printf("The item deleted is %d\n", cur->info);
    free(cur);
    return prev;  // Return new last node
}

// Display the elements of the circular linked list
void display(NODE last) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    NODE cur = last->link;
    do {
        printf("%d ", cur->info);
        cur = cur->link;
    } while (cur != last->link);
    printf("\n");
}

// Search for an element in the circular linked list
void search(NODE last, int key) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    NODE cur = last->link;
    do {
        if (cur->info == key) {
            printf("Key found\n");
            return;
        }
        cur = cur->link;
    } while (cur != last->link);
    printf("Key not found\n");
}

// Main function
int main() {
    NODE last = NULL;
    int op, item, key;

    for (;;) {
        printf("\nMenu\n");
        printf("1. Insert from front\n");
        printf("2. Insert from rear\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Display\n");
        printf("6. Search\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                last = insert_front(last, item);
                break;
            case 2:
                printf("Enter the element to be inserted: ");
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
                printf("Enter the key to be searched: ");
                scanf("%d", &key);
                search(last, key);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
