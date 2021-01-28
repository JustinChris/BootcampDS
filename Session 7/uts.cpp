#include <stdio.h>
#include <stdlib.h>


struct Node {
    int index;
    int gp;
    int level;
    Node *left, *right;
};

int max (int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(Node *root) {
    return (root) ? root->level : 0;
}

int computeNewHeight (Node *root) {
    return max(getHeight(root->left),getHeight(root->right)) + 1;
}

Node *createNode (int index, int gp) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->index = index;
    temp->gp = gp;
    temp->left = temp->right = NULL;
    return temp;
}

Node *insertNode(Node *root, int index, int gp){
    if (!root) {
        return createNode(index,gp);
    }else if (index < root->index) {
        root->left = insertNode(root->left,index,gp);
    }else if (index > root->index) {
        root->right = insertNode(root->right,index,gp);
    }
    return root;
}

Node *inOrderSuccessor (Node *root) {
    Node *curr = root->right;

    while(curr && curr->left) {
        curr = curr->left;
    }
    return curr;
}

Node *inOrderPredecessor (Node *root) {
    Node *curr = root->right;

    while(curr && curr->right) {
        curr = curr->right;
    }
    return curr;
}

Node *deleteNode(Node *root, int index, int gp) {
    if (!root) {
        return root;
    }else if (index < root->index) {
        root->left = deleteNode(root->left,index,gp);
    }else if (index > root->index) {
        root->right = deleteNode(root->right,index,gp);
    }else {
        if (!root->left || !root->right) {
            Node *newRoot = root->left ? root->left : root->right;
            free(root);
            root = NULL;
            return newRoot;
        }
        Node *newRoot = inOrderSuccessor(root);
        root->index = newRoot->index;
        root->gp = newRoot->gp;
        root->right = deleteNode(root->right,newRoot->index,newRoot->gp);
    }
    return root;
}

void displayMainMenu() {
    printf("Hov Mining Simulator\n");
    printf("======================\n");
    puts("[1] Insert Mining Data");
    puts("[2] Display All Cave Data");
    puts("[3] Display Mining Reports");
    puts("[4] Exit");
    printf(">> ");
}

Node *menuInsertMiningData(Node *root) {
    int caveIndex;          //value between 1-999
    int goldProductions;    //value between 1-100
    bool acc = false;

    while(!acc){
        system("cls");
        printf("Input cave index [1-999]\t: ");
        scanf("%d",&caveIndex);
        if (caveIndex > 999 || caveIndex < 1){
            acc = false;
            printf("Value must be between 1 until 999\n");
        }else {
            acc = true;
        }
        printf("Press enter\n");
        getchar();
        getchar();
    }
    acc = false;

    while (!acc) {
        printf("Input gold production [1-100]\t: ");
        scanf("%d",&goldProductions);
        if (caveIndex > 100 || caveIndex < 1){
            puts("Value must between 1 until 100");
            acc = false;
        }else {
            acc = true;
        }
        printf("Press enter\n");
        getchar();
        getchar();
    }
    
    printf("New cave index detected.\n");
    printf("Total gold production for cave %d is %d\n",caveIndex,goldProductions);
    getchar();
    root = insertNode(root,caveIndex,goldProductions);
    return root;
}

void inOrder(Node *root) {
    if (root) {
        inOrder(root->left);
        printf(">> Cave %d (depth 1), total gold productio: %d\n",root->index,root->gp);
        inOrder(root->right);
    }
}


Node *displayCavedata(Node *root) {
    inOrder(root);
    getchar();
    printf("Press enter to continue\n");
    getchar();
}









int main() {
    Node *baseRoot = NULL;
    int menus;
    bool ask = true;
    while(ask) {
        system("cls");
        displayMainMenu();
        
        scanf("%d",&menus);
        switch(menus) {
            case 1: baseRoot = menuInsertMiningData(baseRoot); break;//insert mining data
            case 2: displayCavedata(baseRoot); break; //display all cave data
            case 3: break; //display mining reports
            case 4: break; //exit
        }
    }

    return 0;
}