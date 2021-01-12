#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node {
    int angka;
    Node* next;
}*head, *tail;

Node* createNode(int angka) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->angka = angka;
    newNode->next=NULL;
    return newNode;
}


void pushTail(int angka) {
 
    Node *temp = createNode(angka);
    if(!head){
        head = tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

void searchList(int x) {
    int a=1;
    Node* curr = head;
    while(curr) {
        if(a==x+1)
        printf("%d",curr->angka);

        curr = curr->next;
        a++;
    }
}

int main() {
    int a[10]={1,3,5,7,9,11,13,15,17,19,20,35,52},n=3;
    printf("Node ke berapa dr belakang?\n");
 
    for(int i=0; i<10; i++) {
        pushTail(a[i]);
    }
    printf("Node ke %d dari blkg:\n",n);
    searchList(10-n);
    return 0;
}