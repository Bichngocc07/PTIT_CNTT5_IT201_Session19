//
// Created by Owner on 7/21/2025.
//
#include <stdio.h>
#include <stdlib.h>

// cấu trúc của Node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Hàm tạo node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int main() {
    int input;
    printf("Nhap so nguyen de tao node: ");
    scanf("%d", &input);

    Node* node = createNode(input);
    printf("Node da tao: { data: %d, left: NULL, right: NULL }\n", node->data);

    // Giải phóng bộ nhớ
    free(node);
    return 0;
}