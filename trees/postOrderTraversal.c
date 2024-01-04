//Karina Moffat

#include <stdio.h>
#include <stdlib.h>

//define the node structure to be used in the binary tree
struct Node{
    char value;
    struct Node *leftChild;
    struct Node *rightChild;
};

//create a function that makes new nodes, using a given char type as the value
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value=data;
    newNode->leftChild=NULL;
    newNode->rightChild=NULL;
    return newNode;
}

//create a function to post order traverse through the tree (left, right, root) and print each value at the node
void postOrder(struct Node *root){
    if(root == NULL)
        return;
    postOrder(root->leftChild);
    postOrder(root->rightChild);
    printf("%c", root->value);
}


int main() {
    char *ptr;
    //char treedata[]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'};
    struct Node* root=createNode('A');
    root->leftChild=createNode('B');
    root->rightChild=createNode('C');
    root->leftChild->leftChild=createNode('D');
    root->leftChild->rightChild=createNode('E');
    root->rightChild->leftChild=createNode('F');
    root->rightChild->rightChild=createNode('G');
    root->leftChild->leftChild->leftChild=createNode('H');
    root->leftChild->leftChild->rightChild=createNode('I');
    root->leftChild->rightChild->leftChild=createNode('J');
    root->rightChild->rightChild->leftChild=createNode('K');

    postOrder(root);
}
