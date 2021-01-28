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
    int value, height, bf;
    Node *left, *right;
};

int max(int a, int b) { // maximum between 2 numbers
    return (a > b) ? a:b;
}

int getHeight(Node *root) { //height of a node
    return (root) ? root->height : 0;
}

int getBalanceFactor(Node *root) {      // height of left child - height of right child
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

int computeNewHeight(Node *root) {  //new height after insertion or deletion
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
    newNode->bf = 0;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *updateNode(Node *root) {
    root->height = computeNewHeight(root);
    root->bf = getBalanceFactor(root);
    return root;
}

Node *leftRotate(Node *root) {
    //1. 2 baris kasi nama
    Node *pivot = root->right;
    Node *temp = pivot->left;
    //2. 2 baris lakukan rotasi
    pivot->left = root;
    root->right = temp;
    //3. 2 baris update tinggi dan bf
    updateNode(root);
    updateNode(pivot);
    // 4. return
    return pivot;
}

Node *rightRotate(Node *root) {
    //1. 2 baris kasi nama
    Node *pivot = root->left;
    Node *temp = pivot->right;
    //2. 2 baris lakukan rotasi
    pivot->right = root;
    root->left = temp;
    //3. 2 baris update tinggi dan bf
    updateNode(root);
    updateNode(pivot);
    // 4. return
    return pivot;
}

Node *rotation (Node *root) {
    if (root->bf < -1 && root->right->bf <= 0) {
       return leftRotate(root);
    } else if (root->bf > 1 && root->left->bf >= 0) {
        return rightRotate(root);
    }else if (root->bf > 1 && root->left->bf < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }else if (root->bf < -1 && root->right->bf > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

Node *insertNode(Node *root, int value) {
    if (!root) {
        return createNode(value);
    } else if (value < root->value) {
        root->left = insertNode(root->left,value);
    } else if (value > root->value) {
        root->right = insertNode(root->right, value);
    }
    return rotation(updateNode(root));
}

Node *Predecessor(Node *root) {
    Node *curr = root->left;

    while(curr && curr->right) {
        curr = curr->right;
    }
    return curr;
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
            root->left = root->right = NULL;
            free(root);
            root = NULL;
            return newRoot;
        }

        Node *inOrderPredecessor = Predecessor(root);
        root->value = inOrderPredecessor->value;
        root->left = deleteNode(root->left, inOrderPredecessor->value);
    }
    //return (root) ? rotation(updateNode(root)) : root;
    return rotation(updateNode(root));
}

void inOrder(Node *root) {
    if (root) {
        inOrder(root->left);
        printf("| %-3d | %4d   | %7d        |\n", root->value, root->height, root->bf);
        inOrder(root->right);
    }
}

int main() {
    Node *baseRoot = NULL;
  int toInsert[] = {10, 11, 12, 5, 3, 2, 8, 7, 4};

  for(int i = 0; i < 9; i++) {
    baseRoot = insertNode(baseRoot, toInsert[i]);
    printf("\nAdded %d to the tree.\n", toInsert[i]);
    printf("| %-3s | %-5s | %-14s |\n", "Key", "Height", "Balance Factor");
    inOrder(baseRoot); getchar();
  }

  for(int i = 0; i < 9; i++) {
    baseRoot = deleteNode(baseRoot, toInsert[i]);
    printf("\nRemoved %d from the tree.\n", toInsert[i]);
    printf("| %-3s | %-5s | %-14s |\n", "Key", "Height", "Balance Factor");
    inOrder(baseRoot); getchar();
  }
  
  return 0;
}