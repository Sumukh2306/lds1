#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employee {
    int id;
    char name[50];
    float salary;
    struct employee *llink;
    struct employee *rlink;
};
typedef struct employee *EMP;

EMP getnode() {
    EMP x;
    x = (EMP)malloc(sizeof(struct employee));
    if (x == NULL) {
        printf("Memory full");
        exit(0);
    }
    return x;
}

EMP insertfront(EMP first, int id, char name[], float salary) {
    EMP temp = getnode();
    temp->id = id;
    strcpy(temp->name, name);
    temp->salary = salary;
    temp->rlink = temp->llink = NULL;
    if (first == NULL)
        return temp;
    temp->rlink = first;
    first->llink = temp;
    return temp;
}

EMP insertrear(EMP first, int id, char name[], float salary) {
    EMP temp = getnode();
    temp->id = id;
    strcpy(temp->name, name);
    temp->salary = salary;
    temp->rlink = temp->llink = NULL;
    if (first == NULL)
        return temp;
    EMP cur = first;
    while (cur->rlink != NULL) {
        cur = cur->rlink;
    }
    cur->rlink = temp;
    temp->llink = cur;
    return first;
}

EMP deletefront(EMP first) {
    if (first == NULL) {
        printf("Empty\n");
        return NULL;
    }
    if (first->rlink == NULL) {
        printf("The employee deleted is ID: %d, Name: %s, Salary: %.2f\n", first->id, first->name, first->salary);
        free(first);
        return NULL;
    }
    EMP second = first->rlink;
    printf("The employee deleted is ID: %d, Name: %s, Salary: %.2f\n", first->id, first->name, first->salary);
    free(first);
    second->llink = NULL;
    return second;
}

EMP deleterear(EMP first) {
    if (first == NULL) {
        printf("Empty\n");
        return first;
    }
    if (first->rlink == NULL) {
        printf("The employee deleted is ID: %d, Name: %s, Salary: %.2f\n", first->id, first->name, first->salary);
        free(first);
        return NULL;
    }
    EMP cur = first, prev = NULL;
    while (cur->rlink != NULL) {
        prev = cur;
        cur = cur->rlink;
    }
    printf("The employee deleted is ID: %d, Name: %s, Salary: %.2f\n", cur->id, cur->name, cur->salary);
    free(cur);
    prev->rlink = NULL;
    return first;
}

void display(EMP first) {
    if (first == NULL) {
        printf("Empty\n");
        return;
    }
    EMP cur = first;
    while (cur != NULL) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", cur->id, cur->name, cur->salary);
        cur = cur->rlink;
    }
}

void search(EMP first, int id) {
    if (first == NULL) {
        printf("List is empty. Employee not found.\n");
        return;
    }

    EMP cur = first;
    while (cur != NULL) {
        if (cur->id == id) {
            printf("Employee found. ID: %d, Name: %s, Salary: %.2f\n", cur->id, cur->name, cur->salary);
            return;
        }
        cur = cur->rlink;
    }

    printf("Employee not found.\n");
}

int main() {
    EMP first = NULL;
    int op, id;
    char name[50];
    float salary;

    for (;;) {
        printf("\nMenu\n 1:Insert front\n 2:Insert rear\n 3:Delete front\n 4:Delete rear\n 5:Display\n 6:Search\n 7:Exit\n");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Enter Employee ID, Name, and Salary: ");
                scanf("%d %s %f", &id, name, &salary);
                first = insertfront(first, id, name, salary);
                break;
            case 2:
                printf("Enter Employee ID, Name, and Salary: ");
                scanf("%d %s %f", &id, name, &salary);
                first = insertrear(first, id, name, salary);
                break;
            case 3:
                first = deletefront(first);
                break;
            case 4:
                first = deleterear(first);
                break;
            case 5:
                display(first);
                break;
            case 6:
                printf("Enter Employee ID to search: ");
                scanf("%d", &id);
                search(first, id);
                break;
            default:
                exit(0);
        }
    }
