#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int roll_no;
    char name[50];
    float marks;
    struct student *link;
};

typedef struct student *STUDENT;

STUDENT getnode() {
    STUDENT x = (STUDENT)malloc(sizeof(struct student));
    if (x == NULL) {
        printf("Memory full\n");
        exit(0);
    }
    return x;
}

STUDENT insertfront(STUDENT first, int roll_no, char name[], float marks) {
    STUDENT temp = getnode();
    temp->roll_no = roll_no;
    strcpy(temp->name, name);
    temp->marks = marks;
    temp->link = NULL;

    if (first == NULL) {
        return temp;
    }
    temp->link = first;
    return temp;
}

STUDENT insertrear(STUDENT first, int roll_no, char name[], float marks) {
    STUDENT cur;
    STUDENT temp = getnode();
    temp->roll_no = roll_no;
    strcpy(temp->name, name);
    temp->marks = marks;
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

STUDENT deletefront(STUDENT first) {
    if (first == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    STUDENT temp = first;
    printf("Deleted Student: Roll No = %d, Name = %s, Marks = %.2f\n", temp->roll_no, temp->name, temp->marks);
    first = first->link;
    free(temp);
    return first;
}

STUDENT deleterear(STUDENT first) {
    if (first == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (first->link == NULL) {
        printf("Deleted Student: Roll No = %d, Name = %s, Marks = %.2f\n", first->roll_no, first->name, first->marks);
        free(first);
        return NULL;
    }
    STUDENT prev = NULL, cur = first;
    while (cur->link != NULL) {
        prev = cur;
        cur = cur->link;
    }
    printf("Deleted Student: Roll No = %d, Name = %s, Marks = %.2f\n", cur->roll_no, cur->name, cur->marks);
    free(cur);
    prev->link = NULL;
    return first;
}

void display(STUDENT first) {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }
    STUDENT cur = first;
    while (cur != NULL) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", cur->roll_no, cur->name, cur->marks);
        cur = cur->link;
    }
}

STUDENT search(int roll_no, STUDENT first) {
    if (first == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    STUDENT cur = first;
    while (cur != NULL) {
        if (cur->roll_no == roll_no) {
            printf("Found Student: Roll No = %d, Name = %s, Marks = %.2f\n", cur->roll_no, cur->name, cur->marks);
            return cur;
        }
        cur = cur->link;
    }
    printf("Student with Roll No %d not found\n", roll_no);
    return NULL;
}

int main() {
    STUDENT first = NULL;
    int op, roll_no;
    char name[50];
    float marks;

    for (;;) {
        printf("Menu\n1: Insert front\n2: Insert rear\n3: Delete front\n4: Delete rear\n5: Display\n6: Search\n7: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Enter Roll No, Name, and Marks: ");
                scanf("%d %s %f", &roll_no, name, &marks);
                first = insertfront(first, roll_no, name, marks);
                break;
            case 2:
                printf("Enter Roll No, Name, and Marks: ");
                scanf("%d %s %f", &roll_no, name, &marks);
                first = insertrear(first, roll_no, name, marks);
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
                printf("Enter Roll No to search: ");
                scanf("%d", &roll_no);
                search(roll_no, first);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
