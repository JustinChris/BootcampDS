/*
kisi kisi belajar 4 materi linked list, bst, hash table, dan stacknQueue file 1 - 7
Catatan Binary Search Trees
1. tree concept
- Tree is a non linear data structure that represents hierarchical relationships
- it is collection of one or more nodes linked by pointers
- pake left and right
- node at the top is called as root
- a line connecting the parent to the child is edge
- nodes that do not have children are called leaf
- nodes that have the same parent are called sibling


2. Binary Tree
- binary tree is a tree data structure where each node has at most two children
- there are 5 types of binary tree: full, complete, perfect, skewed, and balanced
- full binary tree = a binary tree that has either zero children or two children.
- complete binary tree = a binary tree where all the tree levels are filled entirely with nodes, except lowest level of the tree.
- prefect binary tree = binary tree where all internal nodes have strictly two children and every leaf node is at the same level within tree.
    o   soalnya ada 1 syarat lagi sbnrnya, yaitu penuh dan mentok ke kiri
    o   jadi setiap anak baru, harus diinsert ke paling kiri
Berdasarkan jumlah Node bisa dibedakan menjadi 2 Balanced dan Skewed
- balanced binary tree = a binary tree with height O(log N), where N is the number of nodes
- We can easily identify a balanced binary tree if the height of the left and the right subree vary by at most one
- degenerate binary tree = mirip sama kayak linked list hanya punya satu anak

khusus untuk perfect binary tree
- jumlah maksimum node di level k adalah 2^k
- jumlah max node di binary tree 2^(h+1) - 1

- tinggi minimum binary tree dengan n node adalah ^2 log(n).
- tinggi maksimum binary tree dengan n node adalah n-1

Binary tree using Array
root is index = 0
left child is = 2p+1, p= index parent
right children is = 2p+2, p = index parent
parent is (p-1)/2

3. Binary Search Tree





*/
#include <stdio.h>
#include <stdlib.h>