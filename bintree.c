#include <stdio.h>
#include <stdlib.h>
#include "linkedqueue.h"


struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct BinaryTree {
    struct TreeNode *head;
};

struct BinaryTree* createBinaryTree();
void insert(struct BinaryTree*, struct TreeNode*);
void inorder(struct TreeNode *node);
void levelorder(struct BinaryTree*);

struct BinaryTree* createBinaryTree() {
    struct BinaryTree *tree = malloc(sizeof(struct BinaryTree));

    if (tree == NULL) {
        perror("Failed to allocate memory for BinaryTree. Exiting\n");
        exit(1);
    }

    tree->head = NULL;

    return tree;
}

void insertHelper(struct TreeNode *subtree, struct TreeNode *node) {
    if (node->value < subtree->value) {
        if (subtree->left)
            insertHelper(subtree->left, node);
        else
            subtree->left = node;
    } else if (node->value > subtree->value) {
        if (subtree->right)
            insertHelper(subtree->right, node);
        else
            subtree->right = node;
    }
}

void insert(struct BinaryTree *tree, struct TreeNode *node) {
    if (tree->head)
        insertHelper(tree->head, node);
    else
        tree->head = node;
}

void inorder(struct TreeNode *node) {
    if (node->left)
        inorder(node->left);

    printf("%d\n", node->value);

    if (node->right)
        inorder(node->right);
}

void levelorder(struct BinaryTree *tree) {
    struct LinkedQueue *queue = newLinkedQueue();
    struct TreeNode *node;

    if (tree->head == NULL)
        return;
    else
        append(queue, tree->head);

    while (!empty(queue)) {
        node = pop(queue);
        printf("%d\n", node->value);

        if (node->left)
            append(queue, node->left);
        if (node->right)
            append(queue, node->right);
    }
}

int main() {
    int i;
    int numbers[] = {7, 8, 22, 4, 55, 35, 2, 9, 30, 30, 24, -124, 135, 1351, 124, 2 << 10, 0};
    struct TreeNode *node;
    struct BinaryTree *tree = createBinaryTree();

    for (i = 0; numbers[i]; i++) {
        node = malloc(sizeof(struct TreeNode));
        node->value = numbers[i];
        node->left = NULL;
        node->right = NULL;
        insert(tree, node);
    }

    printf("In Order\n");
    inorder(tree->head);

    printf("\nLevel Order\n");
    levelorder(tree);

    return 0;
}
