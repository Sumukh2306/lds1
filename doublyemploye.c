#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for an employee
struct employee {
    int id;
    char name[50];
    float salary;
    struct employee *llink;
    struct employee *rlink;
};
typedef struct employee *EMP;

// Function to create a new node
EMP getnode() {
    EMP x = (EMP)malloc(sizeof(struct employee));
    if (x == NULL) {
        printf("Memory full\n");
        exit(0);
    }
    return x;
}

// Function to insert a node at the front
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

// Function to insert a node at the rear
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

// Function to delete a node from the front
EMP deletefront(EMP first) {
    if (first == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (first->rlink == NULL) {
        printf("Employee deleted: ID: %d, Name: %s, Salary: %.2f\n", first->id, first->name, first->salary);
        free(first);
        return NULL;
    }
    EMP second = first->rlink;
    printf("Employee deleted: ID: %d, Name: %s, Salary: %.2f\n", first->id, first->name, first->salary);
    free(first);
    second->llink = NULL;
    return second;
}

// Function to delete a node from the rear
EMP deleterear(EMP first) {
    if (first == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (first->rlink == NULL) {
        printf("Employee deleted: ID: %d, Name: %s, Salary: %.2f\n", first->id, first->name, first->salary);
        free(first);
        return NULL;
    }
    EMP cur = first;
    while (cur->rlink != NULL) {
        cur = cur->rlink;
    }
    printf("Employee deleted: ID: %d, Name: %s, Salary: %.2f\n", cur->id, cur->name, cur->salary);
    cur->llink->rlink = NULL;
    free(cur);
    return first;
}

// Function to display all nodes
void display(EMP first) {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }
    EMP cur = first;
    while (cur != NULL) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", cur->id, cur->name, cur->salary);
        cur = cur->rlink;
    }
}

// Function to search for an employee by ID
void search(EMP first, int id) {
    if (first == NULL) {
        printf("List is empty. Employee not found.\n");
        return;
    }
    EMP cur = first;
    while (cur != NULL) {
        if (cur->id == id) {
            printf("Employee found: ID: %d, Name: %s, Salary: %.2f\n", cur->id, cur->name, cur->salary);
            return;
        }
        cur = cur->rlink;
    }
    printf("Employee not found.\n");
}

// Main function
int main() {
    EMP first = NULL;
    int op, id;
    char name[50];
    float salary;

    for (;;) {
        printf("\nMenu\n");
        printf("1: Insert front\n");
        printf("2: Insert rear\n");
        printf("3: Delete front\n");
        printf("4: Delete rear\n");
        printf("5: Display\n");
        printf("6: Search\n");
        printf("7: Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &op) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

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
            case 7:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}
