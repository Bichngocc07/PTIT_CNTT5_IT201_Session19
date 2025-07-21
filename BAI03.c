//
// Created by Owner on 7/21/2025.
//
#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc nút của cây
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Hàm tạo một nút mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong cap phat đuoc bo nho!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm duyệt cây theo thứ tự tiền tự (Preorder)
void preorder(Node* root) {
    if (root != NULL) {
        printf("%d\n", root->data);     // Gốc
        preorder(root->left);           // Trái
        preorder(root->right);          // Phải
    }
}

int main() {

    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->right = createNode(5);

    // Duyệt cây theo Preorder
    printf("Duyet cay Preorder:\n");
    preorder(root);

    return 0;
}
