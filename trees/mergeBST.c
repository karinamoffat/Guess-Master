//Karina Moffat
#include <stdlib.h>
#include <stdio.h>

//define a node
struct node{
    int value;
    struct node *leftchild;
    struct node *rightchild;
};

typedef struct node Node;

//define  a tree
struct tree{
    Node* root;
};

typedef struct tree Tree;

//define a queue
struct queue {
    struct queue* next;
    Node* value;
};

typedef struct queue Queue;

//a function used to create a node using given data
Node* createnode(int data){
    Node* node=(Node*)malloc(sizeof(Node));
    if(node==NULL)
        return node;
    else{
        node->value=data;
        node->leftchild=NULL;
        node->rightchild=NULL;
        return node;
    }
}

//a function to create a tree using given data
Tree* createtree(int data){
    // allocating memory for tree
    Tree* t = malloc(sizeof(Tree));
    // if memory is allocated assign root of tree
    if (t != NULL)
        t->root = createnode(data);
    // return created tree
    return t;
}

//a function used to insert a node into a tree using given data and node
Node* insert (int data, Node* node){
    if(node == NULL) {
        return createnode(data);
    }
    else if(data < (node->value)){
        node->leftchild = insert(data, node->leftchild);
    }
    if(data >(node->value)){
        node->rightchild = insert(data, node->rightchild);
    }
    return node;
}

//a function used to build the tree
void buildTree(Node* root, int data){
    //duplicate values can be inserted into the right subtree
    //if right child already exists, inert into left subtree
    if(root->value == data){
        if(root->rightchild == NULL){
           //make a new node using the given data and set it equal to the right child
            Node *new = createnode(data);
            root->rightchild = new;
        } else {
            Node *new = createnode(data);
            root->leftchild = new;
        }
    }

    //iterate through right subtree if the data is greater than the data of the current node and a right child exists
    if(data < root->value && root->leftchild!=NULL)
        buildTree(root->leftchild, data);
    else if (root->leftchild == NULL && data<root->value) {
        Node *new = createnode(data);
        root->leftchild = new;

    }

        //iterate through the left subtree if the data is less than the data of the current node and a left child exists
    else if(data > root->value && root->rightchild !=NULL)
        buildTree(root->rightchild, data);
        //If there is no right child.
    else if (root->rightchild == NULL) {
        //If there is no right child.
        Node *new = createnode(data);
        root->rightchild = new;
    }

    if(root == NULL){
        return;
    }
    return;
}

//a function to compare the two roots of two trees
Tree *compareRoots (Tree* root1, Tree* root2){
    if (root1->root->value < root2->root->value){
        return createtree(root1->root->value);
    }else{
        return createtree(root2->root->value);
    }
}

//a function to find the minimum value
Node* findmin(Node *node){
    if(node==NULL)
        return NULL;
    else if(node->leftchild!=NULL)
        //go through find min function down the left branches bc that's where all the min values are
        return findmin(node->leftchild);
    else
        return node;
}

//a delete function to be used to delete a node once it has been merged
void delete(Node* root, Node* target){
    //if the rightchild is the target...
    if (root->rightchild == target){
        if(target->rightchild!=NULL){
            root->rightchild = target->rightchild;
            free(target);
        }else if (target->leftchild!=NULL){
            root->rightchild = target->leftchild;
            free(target);
        }else{
            root->rightchild = NULL;
        }
    }

    //if the leftchild is the target...
   else if(root->leftchild == target){
        if(target->rightchild!=NULL){
            root->leftchild = target->rightchild;
            free(target);
        }else if(target->leftchild!=NULL){
            root->leftchild = target->leftchild;
            free(target);
        }else{
            root->leftchild = NULL;
        }
    }

        //if target node has not been found iterate through the left and right subtrees
    else{
        if(target->value > root->value && root->rightchild != NULL){
            delete(root->rightchild, target);
        }else if (target->value < root->value && root->leftchild!=NULL){
            delete(root->leftchild, target);
        }
    } return;
}


//a merge function to merge the two trees using both of their roots
void merge(Node* root1, Node* root2, Node* mergedRoot){
    //if both root values are equal...
    if (root1->value == mergedRoot->value){
        //iterate through the left subtree of first tree
        //node with lowest value gets merged into the merged tree and deleted
        while(root1->leftchild!=NULL){
            Node* min1 = findmin(root1);
            buildTree(mergedRoot, min1->value);
            delete(root1, min1);
        }
        //iterate through right subtree of first tree
        //node with lowest value gets merged into the merged tree and deleted
        while(root1->rightchild!=NULL){
            Node* min1 = findmin(root1->rightchild);
            buildTree(mergedRoot, min1->value);
            delete(root1, min1);
        }

        //call the build tree function to insert root of second tree into merged tree
        buildTree(mergedRoot, root2->value);

        //iterate through left subtree of second tree
        //node with lowest value gets merged into the merged tree and deleted
        while(root2->leftchild!=NULL){
            Node* min2 = findmin(root2);
            buildTree(mergedRoot, min2->value);
            delete(root2, min2);
        }
        //iterate through right subtree of second tree
        //node with lowest value gets merged into the merged tree and deleted
        while(root2->rightchild!=NULL){
            Node* min2 = findmin(root2->rightchild);
            buildTree(mergedRoot, min2->value);
            delete(root2, min2);
        }

    }

    else if (root2->value == mergedRoot->value){
        //iterate through the left subtree of tree 2
        //node with lowest value gets merged into the merged tree and deleted
        while(root2->leftchild!=NULL){
            Node* min2 = findmin(root2);
            buildTree(mergedRoot, min2->value);
            delete(root2, min2);
        }
        //iterate through the right subtree of tree 2
        //node with lowest value gets merged into the merged tree and deleted
        while(root2->rightchild!=NULL){
            Node* min2 = findmin(root2->rightchild);
            buildTree(mergedRoot, min2->value);
            delete(root2, min2);
        }

        //call the build tree function to insert the insert root of first tree into merged tree
        buildTree(mergedRoot, root1->value);

        //iterate through left subtree of tree 1
        //node with lowest value gets merged into the merged tree and delete
        while(root1->leftchild!=NULL){
            Node* min1 = findmin(root1);
            buildTree(mergedRoot, min1->value);
            delete(root1, min1);
        }
        //iterate through the right subtree of tree 1
        //node with lowest value gets merged into the merged tree and deleted
        while(root1->rightchild!=NULL){
            Node* min1 = findmin(root1->rightchild);
            buildTree(mergedRoot, min1->value);
            delete(root1, min1);
        }
    } return;
}

//to be used in queue:
//set counter and size to zero initially, merged values will be stored in merged array to be used when printed
int counter= 0;
int mergedArray[9];
int size = 0;

//set the front and end of the queue to null
Queue* front=NULL;
Queue* end=NULL;


//a function to enqueue nodes to the queue
void enqueue(Node* node){
    Queue* new = (Queue*)malloc(sizeof(Queue));
    new->value = node;

    //if node is the first node in queue
    if(front == NULL && front == NULL){
        front = new;
        end = new;
    }else{
        end->next = new;
        end = new;
    }counter++;
    return;
}

//a function to dequeue
void dequeue(){
    //if there is a left child enqueue it
    if(front->value->leftchild != NULL){
        enqueue(front->value->leftchild);
    }
    //if there is a right child enqueue it
    if (front->value->rightchild != NULL){
        enqueue(front->value->rightchild);
    }

    //the index i of the merged array is the value of the front before deletion happens
    mergedArray[size] = front->value->value;
    size++;

    //Delete the node!
    Queue* new = front;
    front = front->next;
    free(new);
    counter--;
    return;
}

//a function to iterate through the tree using breadth first traversal
void breadthFirstTraversal(Node* root){
    //start by enqueuing the root
        enqueue(root);
        //continue to dequeue until there are no more nodes left
        while(counter!=0){
            dequeue();
        } return;
    }

int main(){
    //build both trees
    Tree* tree1 = createtree(3);
    buildTree(tree1->root,2);
    buildTree(tree1->root,1);
    buildTree(tree1->root,5);
    Tree* tree2 = createtree(4);
    buildTree(tree2->root,1);
    buildTree(tree2->root,2);
    buildTree(tree2->root,7);
    buildTree(tree2->root,9);

    //compare the roots of both trees and store it in the new tree, mergedTree
    Tree* mergedTree = compareRoots(tree1,tree2);

    //merge the trees by passing both of them through merge function
    //will build the new tree mergedTree
    merge(tree1->root, tree2->root, mergedTree->root);
    breadthFirstTraversal(mergedTree->root);

    //print through the array holding the breadth first traversal of the merged tree
    for(int i = 0; i<size; i++){
        printf("%d ", mergedArray[i]);
    }
    return 0;
}
