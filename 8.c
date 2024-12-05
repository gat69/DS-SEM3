#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
struct node {
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node *NODE;

// Function to create a new node
NODE create_node(int item) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function to insert a node into the BST
NODE Insertbst(NODE root, int item) {
    if (root == NULL) {
        return create_node(item);
    }
    if (item < root->data) {
        root->left = Insertbst(root->left, item);
    } else {
        root->right = Insertbst(root->right, item);
    }
    return root;
}

// Preorder traversal of the BST
void preorder(NODE root) {
    if (root != NULL) {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder traversal of the BST
void inorder(NODE root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

// Postorder traversal of the BST
void postorder(NODE root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

// Main function
int main() {
    NODE root = NULL;
    int ch, item;

    while (1) {
        printf("\n1. Insert");
        printf("\n2. Preorder Traversal");
        printf("\n3. Inorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter the element to be inserted: ");
                scanf("%d", &item);
                root = Insertbst(root, item);
                break;
            case 2:
                printf("\nPreorder Traversal:\n");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("\nInorder Traversal:\n");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("\nPostorder Traversal:\n");
                postorder(root);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}
