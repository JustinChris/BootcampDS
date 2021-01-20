/*
https://elvanselvano.medium.com/avl-tree-perfectly-balanced-as-all-things-should-be-ca15a6d59ac5

rotation (balancing) tujuannya adalah untuk membuat tree kita menjadi compact, di layar, dari 3 level menjadi 2 level aja
kita ga bisa sekedar swap sih.

tujuan dari si avl ini adala untuk memperbaiki imbalance dari sebuah bst. 
kalua kita hanya swap keynya saja, dan struktur tree kita masih sama, berarti tree kita ga menjadi balance
tujuan dari rotation ini adalah untuk membalance sebuah tree
bukan hanya menjaga search property. makanya avl itu sebutannya adaah self-balance tree




*/
#include <stdio.h>
#include<stdlib.h>

struct Node {
    int value, height;
    Node *left, *right;
};

int max(int a, int b) {
    return (a > b) ? a:b;
}

int getHeight(Node *root) {
    return (root) ? root->height : 0;
}

int getBalanceFactor(Node *root) {
    return (root) ? getHeight(root->left) - getHeight(root->right) : 0;
    //sama aja kayak gini
    // if(root) {
    //     int heightLeftSubtree = getHeight(root->left);
    //     int heightRightSubtree = getHeight(root->right);
    //     int difference = heightLeftSubtree - heightRightSubtree;
    //     if (difference < 0) {
    //         difference*= -1;
    //     return difference;}
    // }else {
    //     int difference2 = 0;
    //     return difference2;
    // }
}

int computeNewHeight(Node *root) {
    //Rumus untuk menentukan tinggi dari sebuah node adalah max value dari tinggi kedua anak ditambah dengan satu.
    return max(getHeight(root->left),getHeight(root->right)) + 1;
    
    //atau seperti ini
    // int heightLeftSubtree = getHeight(root->left);
    // int heightRightSubtree = getHeight(root->right);
    // int maxHeight = max(heightLeftSubtree,heightRightSubtree);
    // int parentHeight = maxHeight + 1;
    // return parentHeight;
}

Node *createNode (int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insertNode(Node *root, int value) {
    if (!root) {
        return createNode(value);
    }else if (value < root->value) {
        root->left = insertNode(root->left,value);
    }else if (value > root->value) {
        root->right = insertNode(root->right, value);
    }

    return rotation(root);
}

Node *inOrderPredecessor(Node *root) {
    Node *curr = root->left;

    while(curr && curr->right) {
        curr = curr->right;
    }
}

Node *deleteNode(Node *root,int value) {
    if (!root) {
        return root;
    } else if (value < root->value) {
        root->left = deleteNode(root->left,value);
    } else if (value > root->value) {
        root->right = deleteNode(root->right,value);
    } else {
        if(!root->left || !root->right) {
            Node *newRoot = root->left ? root->left : root->right;
            free(root);
            root = NULL;
            return newRoot;
        }

        Node *inOrderPredecessor = inOrderPredecessor(root);
        root->value = inOrderPredecessor->value;
        root->left = deleteNode(root->left, inOrderPredecessor->value);
    }
    return (root) ? rotation(root) : root;
}

int main() {
    Node *baseRoot = NULL;


    return 0;
}