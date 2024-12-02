#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
    int rollno;
    char name[50];
    float marks;
    struct student *llink;
    struct student *rlink;
};
typedef struct student *STUD;

STUD getnode() {
    STUD x;
    x = (STUD)malloc(sizeof(struct student));
    if (x == NULL) {
        printf("Memory full");
        exit(0);
    }
    return x;
}

STUD insertfront(STUD first, int rollno, char name[], float marks) {
    STUD temp = getnode();
    temp->rollno = rollno;
    strcpy(temp->name, name);
    temp->marks = marks;
    temp->rlink = temp->llink = NULL;
    if (first == NULL)
        return temp;
    temp->rlink = first;
    first->llink = temp;
    return temp;
}

STUD insertrear(STUD first, int rollno, char name[], float marks) {
    STUD temp = getnode();
    temp->rollno = rollno;
    strcpy(temp->name, name);
    temp->marks = marks;
    temp->rlink = temp->llink = NULL;
    if (first == NULL)
        return temp;
    STUD cur = first;
    while (cur->rlink != NULL) {
        cur = cur->rlink;
    }
    cur->rlink = temp;
    temp->llink = cur;
    return first;
}

STUD deletefront(STUD first) {
    if (first == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (first->rlink == NULL) {
        printf("The student deleted is Roll No: %d, Name: %s, Marks: %.2f\n", first->rollno, first->name, first->marks);
        free(first);
        return NULL;
    }
    STUD second = first->rlink;
    printf("The student deleted is Roll No: %d, Name: %s, Marks: %.2f\n", first->rollno, first->name, first->marks);
    free(first);
    second->llink = NULL;
    return second;
}

STUD deleterear(STUD first) {
    if (first == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (first->rlink == NULL) {
        printf("The student deleted is Roll No: %d, Name: %s, Marks: %.2f\n", first->rollno, first->name, first->marks);
        free(first);
        return NULL;
    }
    STUD cur = first, prev = NULL;
    while (cur->rlink != NULL) {
        prev = cur;
        cur = cur->rlink;
    }
    printf("The student deleted is Roll No: %d, Name: %s, Marks: %.2f\n", cur->rollno, cur->name, cur->marks);
    free(cur);
    prev->rlink = NULL;
    return first;
}

void display(STUD first) {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }
    STUD cur = first;
    while (cur != NULL) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", cur->rollno, cur->name, cur->marks);
        cur = cur->rlink;
    }
}

void search(STUD first, int rollno) {
    if (first == NULL) {
        printf("List is empty. Student not found.\n");
        return;
    }
    STUD cur = first;
    while (cur != NULL) {
        if (cur->rollno == rollno) {
            printf("Student found. Roll No: %d, Name: %s, Marks: %.2f\n", cur->rollno, cur->name, cur->marks);
            return;
        }
        cur = cur->rlink;
    }
    printf("Student not found.\n");
}

int main() {
    STUD first = NULL;
    int op, rollno;
    char name[50];
    float marks;

    for (;;) {
        printf("\nMenu\n 1: Insert front\n 2: Insert rear\n 3: Delete front\n 4: Delete rear\n 5: Display\n 6: Search\n 7: Exit\n");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Enter Roll No, Name, and Marks: ");
                scanf("%d %s %f", &rollno, name, &marks);
                first = insertfront(first, rollno, name, marks);
                break;
            case 2:
                printf("Enter Roll No, Name, and Marks: ");
                scanf("%d %s %f", &rollno, name, &marks);
                first = insertrear(first, rollno, name, marks);
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
                scanf("%d", &rollno);
                search(first, rollno);
                break;
            default:
                exit(0);
        }
    }
}
