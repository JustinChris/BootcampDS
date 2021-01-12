#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    int value;
    node *next;
} *head, *tail;

node *createNode (int score){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->value = score;
    
}


int main() {
    

    return 0;
}