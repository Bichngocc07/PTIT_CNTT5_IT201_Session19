//
// Created by Owner on 7/21/2025.
//
#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc của một nút trong cây
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Hàm tạo nút mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Không cấp phát được bộ nhớ!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm duyệt hậu tự (Postorder): Trái → Phải → Gốc
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d\n", root->data);
    }
}

// Hàm main
int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    // Duyệt hậu tự
    printf("Duyet cay hau tu (Postorder):\n");
    postorder(root);

    return 0;
}
