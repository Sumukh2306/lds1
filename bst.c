
#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *left;
    struct node *right;
};
typedef struct node *NODE;

// Function to create a new node
NODE getnode(int item) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory full\n");
        exit(0);
    }
    temp->info = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a node into the BST
NODE insert(NODE root, int item) {
    if (root == NULL) {
        return getnode(item);
    }
    if (item < root->info) {
        root->left = insert(root->left, item);
    } else if (item > root->info) {
        root->right = insert(root->right, item);
    } else {
        printf("Duplicate key not allowed\n");
    }
    return root;
}

// Function to find the minimum value node in a subtree
NODE findMin(NODE root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
NODE deleteNode(NODE root, int key) {
    if (root == NULL) {
        printf("Key not found\n");
        return NULL;
    }

    if (key < root->info) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->info) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with one or no child
        if (root->left == NULL) {
            NODE temp = root->right;
            printf("Deleted key: %d\n", root->info);
            free(root);
            return temp;
        } else if (root->right == NULL) {
            NODE temp = root->left;
            printf("Deleted key: %d\n", root->info);
            free(root);
            return temp;
        }

        // Node with two children
        NODE temp = findMin(root->right);
        root->info = temp->info;
        root->right = deleteNode(root->right, temp->info);
    }
    return root;
}

// Function to search for a key in the BST
void search(NODE root, int key) {
    if (root == NULL) {
        printf("Key not found\n");
        return;
    }
    if (key == root->info) {
        printf("Key found\n");
    } else if (key < root->info) {
        search(root->left, key);
    } else {
        search(root->right, key);
    }
}

// Function for in-order traversal
void inorder(NODE root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d\n", root->info);
        inorder(root->right);
    }
}

// Function for pre-order traversal
void preorder(NODE root) {
    if (root != NULL) {
        printf("%d\n", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function for post-order traversal
void postorder(NODE root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d\n", root->info);
    }
}

int main() {
    NODE root = NULL;
    int op, item, key;

    for (;;) {
        printf("\nMenu\n");
        printf("1: Insert\n");
        printf("2: Delete\n");
        printf("3: Search\n");
        printf("4: Display In-order\n");
        printf("5: Display Pre-order\n");
        printf("6: Display Post-order\n");
        printf("7: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                root = insert(root, item);
                break;
            case 2:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
            case 3:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                search(root, key);
                break;
            case 4:
                printf("In-order traversal:\n");
                inorder(root);
                break;
            case 5:
                printf("Pre-order traversal:\n");
                preorder(root);
                break;
            case 6:
                printf("Post-order traversal:\n");
                postorder(root);
                break;
            default:
                exit(0);
        }
    }
    return 0;
}
