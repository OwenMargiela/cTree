#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum Ptr {
    Left,
    Right
};

typedef struct TreeNode {
    double val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

void InitializeTreeNode(TreeNode* treeNode) {
    treeNode->left = NULL;
    treeNode->right = NULL;
}

TreeNode* Getmin(TreeNode* root) {
    TreeNode* cur = root;
    while (cur && cur->left) {
        cur = cur->left;
    }
    return cur;
}

TreeNode* CreateTreeNode(double key) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node != NULL) {
        InitializeTreeNode(node);
        node->val = key;
    }
    return node;
}

TreeNode* Find(TreeNode* root, double key) {
    if (root == NULL || root->val == key) {
        return root;
    }

    if (root->val > key) {
        return Find(root->left, key);
    }
    else {
        return Find(root->right, key);
    }
}

bool Contains(TreeNode* root, double key) {
    return Find(root, key) != NULL;
}

TreeNode* Insert(TreeNode* root, double key) {
    if (Contains(root, key)) {
        return root;
    }

    if (root == NULL) {
        return CreateTreeNode(key);
    }

    if (root->val > key) {
        root->left = Insert(root->left, key);
    }
    else if (root->val < key) {
        root->right = Insert(root->right, key);
    }

    return root;
}

TreeNode* Remove(TreeNode* root, double key) {
    if (root == NULL) {
        return root;
    }

    if (root->val > key) {
        root->left = Remove(root->left, key);
    }
    else if (root->val < key) {
        root->right = Remove(root->right, key);
    }
    else {
        if (!root->right) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        else if (!root->left) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else {
            root->val = Getmin(root->right)->val;
            root->right = Remove(root->right, root->val);
        }
    }

    return root;
}

void FreeTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    FreeTree(root->left);
    FreeTree(root->right);
    free(root);
}

void PrintPtr(TreeNode* root, enum Ptr ptr) {
    if (ptr == Right) {
        if (root->right)
            printf("%.2lf rightPointer -> %.2lf \n", root->val, root->right->val);
        else
            printf("No right pointer\n");
    }

    else if (ptr == Left) {
        if (root->left)
            printf("%.2lf  <- %.2lf leftpointer", root->left->val, root->val);
        else {
            printf("No left pointer\n");
        }
    }
}

TreeNode* FindParent(TreeNode* root, double key) {
    if (root == NULL ||
        (root->left != NULL && root->left->val == key) ||
        (root->right != NULL && root->right->val == key)) {
        return root;
    }

    if (root->val > key) {
        return FindParent(root->left, key);
    }
    else {
        return FindParent(root->right, key);
    }
}
