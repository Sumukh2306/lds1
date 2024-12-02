#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    int id;
    char name[50];
    float salary;
    struct employee *link;
};

typedef struct employee *EMPLOYEE;

EMPLOYEE getnode() {
    EMPLOYEE x = (EMPLOYEE)malloc(sizeof(struct employee));
    if (x == NULL) {
        printf("Memory full\n");
        exit(0);
    }
    return x;
}

EMPLOYEE insertfront(EMPLOYEE first, int id, char name[], float salary) {
    EMPLOYEE temp = getnode();
    temp->id = id;
    strcpy(temp->name, name);
    temp->salary = salary;
    temp->link = NULL;

    if (first == NULL) {
        return temp;
    }
    temp->link = first;
    return temp;
}

EMPLOYEE insertrear(EMPLOYEE first, int id, char name[], float salary) {
    EMPLOYEE cur;
    EMPLOYEE temp = getnode();
    temp->id = id;
    strcpy(temp->name, name);
    temp->salary = salary;
    temp->link = NULL;

    if (first == NULL) {
        return temp;
    }

    cur = first;
    while (cur->link != NULL) {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}

EMPLOYEE deletefront(EMPLOYEE first) {
    if (first == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    EMPLOYEE temp = first;
    printf("Deleted Employee: ID = %d, Name = %s, Salary = %.2f\n", temp->id, temp->name, temp->salary);
    first = first->link;
    free(temp);
    return first;
}

EMPLOYEE deleterear(EMPLOYEE first) {
    if (first == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (first->link == NULL) {
        printf("Deleted Employee: ID = %d, Name = %s, Salary = %.2f\n", first->id, first->name, first->salary);
        free(first);
        return NULL;
    }
    EMPLOYEE prev = NULL, cur = first;
    while (cur->link != NULL) {
        prev = cur;
        cur = cur->link;
    }
    printf("Deleted Employee: ID = %d, Name = %s, Salary = %.2f\n", cur->id, cur->name, cur->salary);
    free(cur);
    prev->link = NULL;
    return first;
}

void display(EMPLOYEE first) {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }
    EMPLOYEE cur = first;
    while (cur != NULL) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", cur->id, cur->name, cur->salary);
        cur = cur->link;
    }
}

EMPLOYEE search(int id, EMPLOYEE first) {
    if (first == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    EMPLOYEE cur = first;
    while (cur != NULL) {
        if (cur->id == id) {
            printf("Found Employee: ID = %d, Name = %s, Salary = %.2f\n", cur->id, cur->name, cur->salary);
            return cur;
        }
        cur = cur->link;
    }
    printf("Employee with ID %d not found\n", id);
    return NULL;
}

int main() {
    EMPLOYEE first = NULL;
    int op, id;
    char name[50];
    float salary;

    for (;;) {
        printf("Menu\n1: Insert front\n2: Insert rear\n3: Delete front\n4: Delete rear\n5: Display\n6: Search\n7: Exit\n");
        printf("Enter your choice: ");
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
                search(id, first);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
