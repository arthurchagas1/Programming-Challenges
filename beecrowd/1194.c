#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 52

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findIndex(char arr[], int start, int end, char value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

Node* buildTree(char infix[], char prefix[], int inStart, int inEnd) {
    Node* stack[MAX_NODES];
    int top = -1;
    Node* root = createNode(prefix[0]);
    Node* curr = root;

    for (int i = 1; i < strlen(prefix); i++) {
        int preIndex = findIndex(infix, inStart, inEnd, prefix[i]);

        if (preIndex < findIndex(infix, inStart, inEnd, curr->data)) {
            curr->left = createNode(prefix[i]);
            stack[++top] = curr;
            curr = curr->left;
        } else {
            while (top != -1 && preIndex > findIndex(infix, inStart, inEnd, stack[top]->data)) {
                curr = stack[top--];
            }
            curr->right = createNode(prefix[i]);
            curr = curr->right;
        }
    }

    return root;
}

void postorderTraversal(Node* root) {
    if (root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%c", root->data);
}

int main() {
    int numCases;
    scanf("%d", &numCases);

    while (numCases--) {
        int numNodes;
        scanf("%d", &numNodes);

        char prefix[MAX_NODES + 1], infix[MAX_NODES + 1];
        scanf("%s %s", prefix, infix);

        Node* root = buildTree(infix, prefix, 0, numNodes - 1);

        postorderTraversal(root);
        printf("\n");
    }

    return 0;
}

