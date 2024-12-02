#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* left;
    struct node* right;
};
typedef struct node* NODE;

// Function to create a new node
NODE getnode(int item) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory is full\n");
        exit(0);
    }
    temp->info = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert a node in BST
NODE insert(NODE root, int item) {
    if (root == NULL) {
        return getnode(item);
    }
    if (item < root->info) {
        root->left = insert(root->left, item);
    } else if (item > root->info) {
        root->right = insert(root->right, item);
    } else {
        printf("Duplicate item not allowed: %d\n", item);
    }
    return root;
}

// Level-order traversal
void level_order(NODE root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    // Queue implementation using a dynamic array
    NODE queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;  // Enqueue root

    while (front < rear) {
        NODE current = queue[front++];  // Dequeue front element

        printf("%d ", current->info);

        // Enqueue left and right children, if they exist
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
    printf("\n");
}

// Other Traversals (In-order, Pre-order, Post-order)
void inorder(NODE root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}

void preorder(NODE root) {
    if (root != NULL) {
        printf("%d ", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(NODE root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->info);
    }
}

// Main Function
int main() {
    NODE root = NULL;
    int op, item;

    for (;;) {
        printf("\nMenu\n");
        printf("1. Insert\n");
        printf("2. In-order Traversal\n");
        printf("3. Pre-order Traversal\n");
        printf("4. Post-order Traversal\n");
        printf("5. Level-order Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                root = insert(root, item);
                break;
            case 2:
                printf("In-order Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Pre-order Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Post-order Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Level-order Traversal: ");
                level_order(root);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
