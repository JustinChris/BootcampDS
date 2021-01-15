#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_ELEMENT = 10;     // jumlah index di hashtable kita
int COLLISION_COUNT = 0;

struct Node {
    char name[255];
    Node *next; // pointer ke node selanjutnya
} *head[MAX_ELEMENT], *tail[MAX_ELEMENT];   // head dan tail global

Node *createNode (const char *str) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, str);
    newNode->next = NULL;
    return newNode;
}


int hash(const char *str) {    
    int sum = 0;

    for (int i = 0; str[i] != '\0';i++) {
        sum += str[i] - '0';    // menjumlahkan ascii dari tiap karakter di dalam string
    }

    return sum % MAX_ELEMENT; //menghindarin index di luar batas
}

void insert(const char *str) {
    int index = hash(str); // dapat index
    Node *temp = createNode(str);   // node baru

    if (head[index]) {  //jika indexnya masih kosong
        head[index] = tail[index] = temp;   //temp akan menjadi head dan tail
    } else { // jika indexnya sudah terisi, lakukan push tail
        COLLISION_COUNT++;
        tail[index]->next = temp;
        tail[index] = temp;
    }

}

void view() {
    for (int i = 0; i < MAX_ELEMENT;i++) {
        //print linked listnya
        printf("Index %d:\n",i);
        if (head[i]) {
            
            Node *curr = head[i];

            while(curr) {
                printf("%s ->",curr->name);
                curr = curr->next;
            }
        }
        puts("NULL\n");
    }
}

int main() {
    insert("carrick");
    insert("bryan");
    insert("nicholas");
    insert("leonardo");
    insert("romario");
    insert("kevin");
    insert("dodi");
    insert("masmas");
    insert("leody");
    insert("jollybee");
    insert("it division");
    insert("saya senang socs");
    insert("zoom meetings");
    insert("cecep");

    view();
    printf("%d\n",COLLISION_COUNT);

    return 0;
}

/*size hashtable kita makin gede makin dikit terjadi collision
soalnya % nya jarang kena
apa lagi jika kalian pakai linear probing, makin kerasa perbedaan antara size kecil dan size besar
*/