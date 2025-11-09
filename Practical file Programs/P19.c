#include <stdio.h>
#include <stdlib.h>

// Structure of node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create node
struct node* createNode(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert node (BST style)
struct node* insertNode(struct node *root, int value) {
    if(root == NULL) {
        return createNode(value);
    }
    else if(value < root->data) {
        root->left = insertNode(root->left, value);
    }
    else {
        root->right = insertNode(root->right, value);
    }
    return root;
}

// Inorder traversal
void inorder(struct node *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder traversal
void preorder(struct node *root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal
void postorder(struct node *root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Main function
int main() {
    struct node *root = NULL;
    int i, val;

    printf("Enter 5 elements for Binary Tree:\n");
    for(i = 0; i < 5; i++) {
        scanf("%d", &val);
        root = insertNode(root, val);
    }

    printf("\nIn-order Traversal: ");
    inorder(root);

    printf("\nPre-order Traversal: ");
    preorder(root);

    printf("\nPost-order Traversal: ");
    postorder(root);

    return 0;
}
