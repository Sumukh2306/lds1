#include <stdio.h>
#include <stdlib.h>
struct node {
    int info;
    struct node *link;
};
typedef struct node *NODE;

NODE getnode() {
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL) {
        printf("Memory full\n");
        exit(0);
    }
    return x;
}

NODE insertfront(NODE first, int item) {
    NODE temp = getnode();
    temp->info = item;
    temp->link = first;
    return temp;
}

NODE insertrear(NODE first, int item) {
    NODE temp = getnode();
    temp->info = item;
    temp->link = NULL;
    if (first == NULL) {
        return temp;
    }
    NODE cur = first;
    while (cur->link != NULL) {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}

NODE insertatpos(NODE first, int item, int pos) {
    NODE temp = getnode();
    temp->info = item;
    temp->link = NULL;

    if (pos <= 1 || first == NULL) { // Insert at the front
        temp->link = first;
        return temp;
    }

    NODE cur = first;
    int count = 1;
    while (cur->link != NULL && count < pos - 1) {
        cur = cur->link;
        count++;
    }
    temp->link = cur->link;
    cur->link = temp;
    return first;
}

NODE deletefront(NODE first) {
    if (first == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    NODE temp = first;
    printf("Item deleted is %d\n", first->info);
    first = first->link;
    free(temp);
    return first;
}

NODE deleterear(NODE first) {
    if (first == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (first->link == NULL) {
        printf("Item deleted is %d\n", first->info);
        free(first);
        return NULL;
    }
    NODE prev = NULL, cur = first;
    while (cur->link != NULL) {
        prev = cur;
        cur = cur->link;
    }
    printf("Item deleted is %d\n", cur->info);
    free(cur);
    prev->link = NULL;
    return first;
}

NODE deleteatpos(NODE first, int pos) {
    if (first == NULL || pos <= 1) { // Delete front
        return deletefront(first);
    }

    NODE prev = NULL, cur = first;
    int count = 1;
    while (cur != NULL && count < pos) {
        prev = cur;
        cur = cur->link;
        count++;
    }
    if (cur == NULL) {
        printf("Invalid position\n");
        return first;
    }
    printf("Item deleted is %d\n", cur->info);
    prev->link = cur->link;
    free(cur);
    return first;
}

void display(NODE first) {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }
    NODE cur = first;
    while (cur != NULL) {
        printf("%d ", cur->info);
        cur = cur->link;
    }
    printf("\n");
}

void search(NODE first, int key) {
    NODE cur = first;
    while (cur != NULL) {
        if (cur->info == key) {
            printf("Key found\n");
            return;
        }
        cur = cur->link;
    }
    printf("Key not found\n");
}

int main() {
    NODE first = NULL;
    int op, item, pos;

    for (;;) {
        printf("\nMenu\n");
        printf("1: Insert front\n2: Insert rear\n3: Insert at position\n4: Delete front\n5: Delete rear\n6: Delete at position\n7: Display\n8: Search\n9: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                first = insertfront(first, item);
                break;
            case 2:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                first = insertrear(first, item);
                break;
            case 3:
                printf("Enter the item and position: ");
                scanf("%d%d", &item, &pos);
                first = insertatpos(first, item, pos);
                break;
            case 4:
                first = deletefront(first);
                break;
            case 5:
                first = deleterear(first);
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                first = deleteatpos(first, pos);
                break;
            case 7:
                display(first);
                break;
            case 8:
                printf("Enter the key to search: ");
                scanf("%d", &item);
                search(first, item);
                break;
            default:
                exit(0);
        }
    }
    return 0;
}
