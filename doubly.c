#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *llink;
    struct node *rlink;
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
    temp->rlink = temp->llink = NULL;
    if (first == NULL)
        return temp;
    temp->rlink = first;
    first->llink = temp;
    return temp;
}

NODE insertrear(NODE first, int item) {
    NODE temp = getnode();
    temp->info = item;
    temp->rlink = temp->llink = NULL;
    if (first == NULL)
        return temp;
    NODE cur = first;
    while (cur->rlink != NULL) {
        cur = cur->rlink;
    }
    cur->rlink = temp;
    temp->llink = cur;
    return first;
}

NODE insertatpos(NODE first, int item, int pos) {
    NODE temp = getnode();
    temp->info = item;
    temp->rlink = temp->llink = NULL;

    if (pos <= 1 || first == NULL) { // Insert at the front
        return insertfront(first, item);
    }

    NODE cur = first;
    int count = 1;
    while (cur->rlink != NULL && count < pos - 1) {
        cur = cur->rlink;
        count++;
    }

    temp->rlink = cur->rlink;
    temp->llink = cur;

    if (cur->rlink != NULL) {
        cur->rlink->llink = temp;
    }

    cur->rlink = temp;
    return first;
}

NODE deletefront(NODE first) {
    if (first == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (first->rlink == NULL) {
        printf("The item deleted is %d\n", first->info);
        free(first);
        return NULL;
    }
    NODE second = first->rlink;
    printf("The item deleted is %d\n", first->info);
    free(first);
    second->llink = NULL;
    return second;
}

NODE deleterear(NODE first) {
    if (first == NULL) {
        printf("List is empty\n");
        return first;
    }
    if (first->rlink == NULL) {
        printf("The item deleted is %d\n", first->info);
        free(first);
        return NULL;
    }
    NODE cur = first;
    while (cur->rlink != NULL) {
        cur = cur->rlink;
    }
    printf("The item deleted is %d\n", cur->info);
    cur->llink->rlink = NULL;
    free(cur);
    return first;
}

NODE deleteatpos(NODE first, int pos) {
    if (first == NULL || pos <= 1) { // Delete front
        return deletefront(first);
    }

    NODE cur = first;
    int count = 1;
    while (cur != NULL && count < pos) {
        cur = cur->rlink;
        count++;
    }

    if (cur == NULL) {
        printf("Invalid position\n");
        return first;
    }

    printf("The item deleted is %d\n", cur->info);

    if (cur->rlink != NULL) {
        cur->rlink->llink = cur->llink;
    }
    if (cur->llink != NULL) {
        cur->llink->rlink = cur->rlink;
    }

    free(cur);
    return first;
}

void display(NODE first) {
    if (first == NULL) {
        printf("Empty\n");
        return;
    }
    NODE cur = first;
    while (cur != NULL) {
        printf("%d\n", cur->info);
        cur = cur->rlink;
    }
}

void search(NODE first, int key) {
    if (first == NULL) {
        printf("List is empty. Key not found.\n");
        return;
    }

    NODE cur = first;
    while (cur != NULL) {
        if (cur->info == key) {
            printf("Key found.\n");
            return;
        }
        cur = cur->rlink;
    }

    printf("Key not found.\n");
}

int main() {
    NODE first = NULL;
    int op, item, key, pos;

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
                scanf("%d", &key);
                search(first, key);
                break;
            default:
                exit(0);
        }
    }
    return 0;
}
