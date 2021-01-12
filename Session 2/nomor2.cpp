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
    newNode->next = NULL;
    return newNode;
}

void pushHead(int score) {
    node *temp = createNode(score);

    if (!head) {
        head = tail = temp;
    }
    else {
        temp->next = head;
        head = temp;
    }
}

void pushTail (int score) {
    node *temp = createNode(score);
    if(!head) {
        head = tail = temp;
    }else {
        tail->next = temp;
        tail = temp;
    }
}

void popHead() {
    if (!head) {
        return;
    }else if  (head == tail) {
        free(head);
        head = tail = NULL;
    }else {
        node *temp = head->next;
        head->next = NULL;
        free(head);
        head = NULL;
    }
}

void popTail() {
    if (!head)return;
    else if (head == tail) {
        free(head);
        head = tail = NULL;
    }else {
        node *temp = head;
        while(temp->next != tail) {
            temp = temp->next;
        }
        temp->next = NULL;
        free(tail);
        tail = temp;
    }
}

int max() {
    int max = 0;
    node *curr = head;
    while(curr) {
        if (max < curr->value){
            max = curr->value;
        }
        curr = curr->next;
    }
    return max;
}
int min() {
    int min = 100000;
    node *curr = head;
    while(curr) {
        if (min > curr->value){
            min = curr->value;
        }
        curr = curr->next;
    }
    return min;
}

int main() {

    pushHead(54);
    pushTail(97);
    pushTail(51);
    pushHead(32);
    pushTail(65);
    pushTail(103);

    printf("nilai max: %d\n",max());
    printf("nilai min: %d\n",min());
    printf("Range: %d\n",max() - min());

    return 0;
}