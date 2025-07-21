//
// Created by Owner on 7/21/2025.
//
#include <stdio.h>
#include <stdlib.h>

//
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
// Hàm tạo một nút mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong cap phat duoc bo nho.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preorder(Node* root) {
    if (root != NULL) {
        printf("%d\n", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Hàm chính
int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->right = createNode(5);

    // Duyệt theo Preorder và in ra kết quả
    printf("Duyet Preorder:\n");
    preorder(root);

    return 0;
}