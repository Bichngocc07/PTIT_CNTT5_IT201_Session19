//
// Created by Owner on 7/21/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Định nghĩa nút cây nhị phân
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Hàm tạo nút mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong cap phat duoc bo nho!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm tìm kiếm DFS trong cây nhị phân
bool searchDFS(Node* root, int target) {
    if (root == NULL) return false;
    if (root->data == target) return true;
    // Đệ quy tìm kiếm trái trước, nếu không thấy thì tìm bên phải
    return searchDFS(root->left, target) || searchDFS(root->right, target);
}

// Hàm main
int main() {
    // Xây dựng cây:
    //        2
    //       / \
    //      3   4
    //     /
    //    5
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int findValue = 3;
    if (searchDFS(root, findValue)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
