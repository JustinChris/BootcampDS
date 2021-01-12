// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// struct Node {
//     char name[255];
//     int score;
//     Node *next; //menunjuk ke node selanjutnya
// } *head, *tail; // global variabel, head dan tail
// // head: node pertama dalam linked list
// // tail: node terakhir dalam linked list


// //char *name sama dengan char name[]
// //const char const char itu gunanya buat kalua kita passing variable yang kita sebut literal string
// //alias kita passingnya beneran string pakai "" dan bukan array

// Node *createNode (const char *name, int score) {
//     Node *newNode = (Node*) malloc(sizeof(Node));
//     strcpy(newNode->name, name);
//     newNode->score = score;
//     newNode->next = NULL;
//     return newNode;
// }

// //push Head, push tail
// void pushHead(const char *name,int score){
//     //1. buat dulu ndoenya
//     //2. cek kondisi
//     //      jika tidak ada head, maka nodenya akan menjadi head dan tail
//     //      jika ada head, node akan menjadi head baru dan node->next = head lama
// /*cara bacanya

// if (!head)

// kalau head berisi NULL

// if (!NULL)
// NULL itu false

// if (!FALSE)
// if (TRUE)
// */


//     Node *temp = createNode(name,score);    //buat dulu nodenya

//     if(!head) { //jika tidak ada head
//         head = tail = temp; //maka nodenya akan menjadi head dan tail
//     }
//     else {     //jika ada head
//         temp->next = head; // node menunjuk ke head yang lama
//         head = temp;    // node akan menjadi head yang baru
//     }
// }

// void pushTail (const char *name, int score) {
//     Node *temp = createNode(name,score);    //buat dulu nodenya

//     if(!head) { //jika tidak ada head
//         head = tail = temp; //maka nodenya akan menjadi head dan tail
//     }
//     else {     //jika ada head
//         tail->next = temp; // tail menunjuk ke node yang baru
//         tail = temp;    // node akan menjadi tail yang baru
//     }
// }

// void popHead() {
//     if(!head) { //jika tidak ada head
//         return;    //langusng return aja
//     }else if (head == tail) {   //kalau node cuman 1
//         free(head);
//         head = tail = NULL;
//     } else { //53 (head) -> 70 -> 40-> 25
//         Node *temp = head->next;    //53 (head) -> 70(temp) -> 40 -> 25
//         head -> next = NULL;        //53(head) -> NULL || 70(temp) -> 40 -> 25
//         free(head);
//         head = temp; // 70 (head,temp) -> 40 -> 25 
//     }
//     //karena temp itu local,
//     // 70 (head) -> 40 -> 25

// }

// void popTail() {
//     if(!head) { // 0 node
//         return;    //langusng return aja
//     }else if (head == tail) {   //kalau node cuman 1
//         free(head);
//         head = tail = NULL;
//     } else { //53 (head) -> 70 -> 40-> 25 ( tail)
//         Node *temp = head;    //53 (head) -> 70(temp) -> 40 -> 25 (tail)
//         while (temp->next != tail) {
//             temp = temp->next;  //jalan terus
//         }

//          //53(head) -> 70(temp) -> 40(temp) -> 25 (tail) -> NULL
//         temp -> next = NULL;   
//         free(head);
//         head = temp; // 70 (head,temp) -> 40 -> 25 

//     }
// }

// int main() {


//     return 0;
// }


// //misalny x itu NULL
// // print x -> value (menghasilkan segmentation fault)

// // if (x != NULL && X->next != NULL) {
//     //do something here...
// //}

// // if (x && x->next) {
// //     //do something here
// // }

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
  char name[255];
  int score;
  Node *next; // node's next pointer
} *head, *tail; // global head and tail

Node *createNode(const char *name, int score) {
  Node *newNode = (Node*)malloc(sizeof(Node)); // allocate memory
  strcpy(newNode->name, name);
  newNode->score = score;
  newNode->next = NULL; // next node is null
  return newNode;
}

void pushHead(const char *name, int score) {
  Node *temp = createNode(name, score); // create new node

  if(!head) { // if there's no head (0 node)
    head = tail = temp;
  } else { // >= 1 node
    temp->next = head; // node points to head
    head = temp; // node becomes head
  }
}

void pushTail(const char *name, int score) {
  // Kita mau pushTail D10 di linked list berikut:
  // A2 (head) -> B3 -> C4 (tail) 

  // D10 (temp) -> NULL || Node *temp = createNode(name, score)
  // A2 (head) -> B3 -> C4 (tail) -> D10 (temp) -> NULL || tail->next = temp
  // A2 (head) -> B3 -> C4 -> D10 (tail) -> NULL || tail = temp

  Node *temp = createNode(name, score); // create new node

  if(!head) { // if there's no head (0 node)
    head = tail = temp;
  } else { // >= 1 node
    tail->next = temp; // tail points to node
    tail = temp; // node becomes tail
  }
}

void popHead() {
  if(!head) { // 0 node
    return;
  } else if(head == tail) { // only 1 node
    free(head); // free allocated memory
    head = tail = NULL; // remove value
  } else { // >= 1 node
    Node *temp = head->next; // 98 (head) -> 100 (temp) -> 95 -> 97 (tail) -> NULL
    head->next = NULL; // 98 (head) -> N || 100 (temp) -> 95 -> 97 (tail) -> NULL
    free(head); // free allocated memory
    head = NULL; // remove value
  }
}

void popTail() {
  if(!head) { // 0 node
    return;
  } else if(head == tail) { // only 1 node
    free(head); // free allocated memory
    head = tail = NULL; // remove value
  } else {
    // INITIAL: 50 (head) -> 54 -> 73 -> 36 (tail) -> NULL
    Node *temp = head; // 50 (head, temp) -> 54 -> 73 -> 36 (tail) -> NULL

    while(temp->next != tail) { // selama node selanjutnya bukan tail
      temp = temp->next; // loop terus
    }

    // 50 (head) -> 54 -> 73 (temp) -> 36 (tail) -> NULL
    temp->next = NULL; // 50 (head) -> 54 -> 73 (temp) -> NULL || 36 (tail) -> NULL
    free(tail); // 50 (head) -> 54 -> 73 (temp) -> NULL
    tail = temp; // 50 (head) -> 54 -> 73 (tail, temp) -> NULL
  }
}

void printLinkedList() {
  Node *curr = head; // set current node to head
                                          
  while(curr) { // while there is still curr
    printf("%s -> ", curr->name);
    curr = curr->next; // move to the next node
  }
  puts("NULL");
}

int main() {
  pushHead("Darnell", 95); // 95 (head, tail) -> NULL
  pushTail("whisper0", 97); // 95 (head) -> 97 (tail) -> NULL
  pushHead("pai", 100); // 100 (head) -> 95 -> 97 (tail) -> NULL
  pushHead("romario", 98); // 98 (head) -> 100 -> 95 -> 97 (tail) -> NULL
  popHead(); // 100 (head) -> 95 -> 97 (tail) -> NULL
  popTail(); // 100 (head) -> 95 (tail) -> NULL
  popTail(); // 100 (head, tail) -> NULL
  popHead(); // NULL
  printLinkedList();

  return 0;
}
