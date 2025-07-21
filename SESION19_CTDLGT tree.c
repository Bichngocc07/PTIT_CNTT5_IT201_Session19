//
// Created by DELL on 7/21/2025.
//DFS_ DUY?T THEO CHI?U S�U  C� 3 C�CH

#include <stdio.h>
#include <stdlib.h>

// BUOC 1:  CAU TRUC 1 NODE TRONG CAY
typedef struct Student {
    int id;
    char name[20];
    char address[50];
} Student;

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// BUOC 2: H�M T?O NODE M?I
Node *createNode(int value) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("cap phat o nho khong thanh cong!");
        return NULL;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// BU?C 3: TRIeN KHAI DFS THEO 3 C�CH
// C�CH 1: INORDER (LEFT_NODE_RIGHT)
void inorder(Node *root) {
    // d�ng h�m d? quy d? duy?t
    // di?u ki?n d?ng c?a h�m
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
}
// C�CH 2: PREORDER( NODE_LEFT_RIGHT)
void preorder(Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d", root->data);
    preorder(root->left);
    preorder(root->right);
}
// C�CH 3: POST_ORDER LEFT_RIGHT_NODE
void postorder(Node *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->data);
}

// BU?C 4: T?O C�Y V� TRI?N KHAI TRONG MAIN
int main() {
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    printf("Duyet cay theo inorder \n");
    // inorder(root);
    preorder(root);
}
