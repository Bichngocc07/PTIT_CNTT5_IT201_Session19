//
// Created by Owner on 7/21/2025.
//
#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc Node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Hàm tạo nút mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong cap phat duoc bo nhoo!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Cấu trúc hàng đợi dùng để duyệt level-order
typedef struct Queue {
    Node* data[100];
    int front, rear;
} Queue;

// Khởi tạo hàng đợi
void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

// Kiểm tra rỗng
int isEmpty(Queue* q) {
    return q->front == q->rear;
}

// Thêm vào hàng đợi
void enqueue(Queue* q, Node* node) {
    q->data[q->rear++] = node;
}

// Lấy phần tử khỏi hàng đợi
Node* dequeue(Queue* q) {
    return q->data[q->front++];
}

// Hàm thêm phần tử vào cây nhị phân theo thứ tự level
void insert(Node* root, int value) {
    if (root == NULL) return;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        Node* current = dequeue(&q);

        if (current->left == NULL) {
            current->left = createNode(value);
            break;
        } else {
            enqueue(&q, current->left);
        }

        if (current->right == NULL) {
            current->right = createNode(value);
            break;
        } else {
            enqueue(&q, current->right);
        }
    }
}

// Hàm duyệt cây theo Preorder để kiểm tra
void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Hàm main
int main() {
    // Tạo cây ban đầu
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    // Thêm giá trị mới
    insert(root, 6);

    // In kết quả để kiểm tra
    printf("Cay sau khi them: ");
    preorder(root);  // Kết quả mong đợi: 2 3 5 6 4
    printf("\n");

    return 0;
}
