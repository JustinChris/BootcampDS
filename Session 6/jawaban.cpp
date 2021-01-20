/*
1. differences between linear and non-linear data structures
array -> 0,1,2,3,4
Linked list -> 0,1,2,3,4,...

Tree non-linear = tidak ada urutan aslinya

2. Describe the following terminology in a tree: base root, key, edge, siblings, parent, child, and leaf
- kita yang nentuin keynya apa
- siblings = yang punya parent sama

3. Explain the following trees: full,complete,perfect
makin kanan makin strict
full -> complete -> perfect

full = setiap komponen hanya punya 0 atau 2 anak
complete = harus keiisi semua kecuali level terakhir
perfect = setiap node punya 2 anak

4. what makes a tree balanced
dikatakan balance jika selisih subtree kanan dan subtree kiri sebesar 1
- Balance factor <= 1
- unbalance = balance factor > 1

5. explain four properties of binary tree

A. Number of nodes
    - max nodes at level k
    - max nodes in a tree with level k
        jumlah node maximal dalam sebuah tree

B. Height of tree
    - min level untuk n nodes
    - max level untuk n nodes

6. Explain the intuition of implementing a binary tree using an array
2p + 1

7. Explain the diffrences between inorder successor and inorder predecessor



*/

// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int value;
//     Node *left,*right;
// };

// Node *createNode (int value) {
//     Node *newNode = (Node*) malloc(sizeof(Node));
//     newNode->value = value;
//     newNode->left = newNode->right = NULL;
//     return newNode;
// }
// /*
// poin penting: node yang akan diinsert pasti akan menjadi leaf
// ga mungkin diselip ke tengah tengah
// */


// Node *insertNode(Node *root, int value) {
//     if (!root) {
//         return createNode(value);
//     }else if (value < root->value) {
//         root->left = insertNode(root->left,value);
//     }else if (value > root->value) {
//         root->right = insertNode(root->right,value);
//     }
//     return root;
// }

// Node *deleteNode(Node *root, int value) {
//     if (!root) {
//         return root;
//     }else if (value < root->value) {
//         root->left = deleteNode(root->left,value);
//     }else if (value > root->value) {
//         root->right = deleteNode(root->right,value);
//     }else {
//         //kasus 0/1 anak (kiri atau kanan)
//         if (!root->left || !root->right) {
//             Node *candidateRoot = (root->left) ? root->left : root->right;
//             free(root);
//             root = NULL;
//             return candidateRoot;
//         }

//         //kasus 2 anak
//         Node *candidateRoot = inOrderPredecessor(root);
//         root->value = candidateRoot->value;
//         root->left = deleteNode(root->left,value);


//     }
// }

// void inOrder(Node *root) {
//     if (root) {
//         inorder(root->left);
//         printf()
//     }
// }


// //dalam bst, root dideclare secara lokal tidak seperti head dan tail yang dideclare global
// int main() {
//     Node *baseRoot = NULL;


//     return 0;
// }
/*
setiap tipe data
itu membutuhkan waktu yang berbeda untuk operasinya
tapi ga sesignifikan itu sampai bkin tle sih
From Made Adi Adnyana to Everyone:  09:13 PM
kalau mau buat fungsi search yang returnnya alamat ke node yang di search bisa kak?
From socs1.binus.ac.id to Everyone:  09:14 PM
soalnya di C, itu kan dekat dengan computer. kita main dengan operasi bit.

int itu 4 bti
long int itu 8 bit

soalnya di C, itu kan dekat dengan computer. kita main dengan operasi bit.

int itu 4 bti
long int itu 8 bit
perbedaan bit ini yang membuat oeprasi menggunakan long int itu lebih lama
"lebih lama" -> ini aku ga tau ya lebih lamanya itu seberapa besar
tapi berdasarkan pengalaman, ga signifikan


*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  Node *left, *right; // left and right child
};

Node *createNode(int value) {
  Node *temp = (Node*)malloc(sizeof(Node));
  temp->value = value;
  temp->left = temp->right = NULL;
  return temp;
}

//                  15
//          10              23
//     8         12     18       27

// 15->left = insertNode(15->left, 13);
// insertNode(10->right, 13);
// insertNode(12->right, 13);
// createNode(13) // stop recursion
// 12->right = 13
// 10->right->right = 13
// 15->left->right->right = 13

Node *insertNode(Node *root, int value) {
  if(!root) { // empty tree
    return createNode(value);
  } else if(value < root->value) { // enter left subtree
    root->left = insertNode(root->left, value);
  } else if(value > root->value) { // enter right subtree
    root->right = insertNode(root->right, value);
  }

  return root;
}

Node *inOrderSucessor(Node *root) { // minimum value in right subtree
  Node *curr = root->right; // root of right subtree

  while(curr && curr->left) { 
    curr = curr->left; // find minimum value by traversing left
  }

  return curr;
}

Node *inOrderPredecessor(Node *root) { // maximum value in left subtree
  Node *curr = root->right; // root of left subtree

  while(curr && curr->right) { 
    curr = curr->right; // find maximum value by traversing right
  }

  return curr;
}

Node *deleteNode(Node *root, int value) {
  if(!root) { // empty tree
    return root;
  } else if(value < root->value) { // enter left subtree
    root->left = deleteNode(root->left, value);
  } else if(value > root->value) { // enter right subtree
    root->right = deleteNode(root->right, value);
  } else {

    if(!root->left || !root->right) { // 0 and 1 child
      // if left child is null, new root is right child
      // if right child is null, new root is left child
      Node *newRoot = root->left ? root->left : root->right;
      free(root); // remove old root
      root = NULL;
      return newRoot;
    }

    // 2 children using inOrderSucessor
    Node *newRoot = inOrderSucessor(root);
    root->value = newRoot->value; // copy value
    root->right = deleteNode(root->right, newRoot->value); // remove the inorder successor

    // 2 children using inOrderPredecessor
    // Node *newRoot = inOrderPredecessor(root);
    // root->value = newRoot->value; // copy value
    // root->right = deleteNode(root->left, newRoot->value); // remove the inorder predecessor
  }

  return root;
}

bool searchNode(Node *root, int key) {
  if(root) {
    if(root->value == key) {
      return true;
    } else if(key < root->value) {
      return searchNode(root->left, key); 
    } else if(key > root->value) {
      return searchNode(root->right, key);
    }
  }

  return false;
}

void preOrder(Node *root) {
  if(root) {
    printf("%d ", root->value);
    preOrder(root->left);
    preOrder(root->right);
  }
}

void inOrder(Node *root) {
  if(root) {
    inOrder(root->left);
    printf("%d ", root->value);
    inOrder(root->right);
  }
}

void postOrder(Node *root) {
  if(root) {
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->value);
  }
}

int main() {
  Node *baseRoot = NULL;
  int toInsert[] = {10, 11, 12, 5, 3, 2, 8, 7, 4, 1, 9, 25, 6, 30, 31};

  for(int i = 0; i < 15; i++) {
    baseRoot = insertNode(baseRoot, toInsert[i]);
    printf("Added %d to the tree.\n", toInsert[i]);
    inOrder(baseRoot);
    puts("");
  }

  for(int i = 0; i < 15; i++) {
    baseRoot = deleteNode(baseRoot, toInsert[i]);
    printf("Removed %d from the tree.\n", toInsert[i]);
    inOrder(baseRoot);
    puts("");
  }

  return 0;
}