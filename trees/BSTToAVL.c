//Karina Moffat
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//define a node
struct node{
    int value;
    struct node *leftchild;
    struct node *rightchild;
};

typedef struct node Node;

//define a tree
struct tree{
    Node *root;
};

typedef struct tree Tree;

//define a queue
struct queueNode {
    Node *value;
    struct queueNode *next;
};

typedef struct queueNode queueNode;

//a function to create a new node using given data
Node* createnode(int data) {
    Node *node = (Node *) malloc(sizeof(Node));
    if (node == NULL)
        return node;
    else {
        node->value = data;
        node->leftchild = NULL;
        node->rightchild = NULL;
        return node;
    }
}

//a function to create a new tree using given data
Tree* createtree(int data){
    // allocating memory for tree
    Tree* t = malloc(sizeof(Tree));
    // if memory is allocated assign root of tree
    if (t != NULL)
        t->root = createnode(data);
    // return created tree
    return t;
}

//a function to insert a node into the tree using the given data and node
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

//a function to build the tree
//will pass the index values of the array storing data values into the insert function
//this will insert each index individually into the tree
Node* buildTree (Node *node){
    int input[10] = {18, 17, 8, 9, 5, 4, 2};
    for (int i = 0; i < 7; i++){
        insert(input[i], node);
    }
    return node;
}

//a function to determine the greater value
int intmax(int a, int b) {
    return (a >= b) ? a : b;
}

//a function to determine the height of a tree when the root is passed through
//the height of an empty tree is -1.  Height of a leaf node is 0. Height of other
//nodes is 1 more than larger height of node's two subtrees.
int height(Node *root){
    int		nodeheight = -1;	// default returned for empty tree
    if (root != NULL) {
        //find height of left and right branch by using a recursive function, will use intmax to find larger height to use
        int leftheight = height(root->leftchild);
        int rightheight = height(root->rightchild);
        //compare which has a greater height, left or right branch. Add 1 to this height because ndoe is 1 more than larger height of node's two subtrees
        nodeheight = intmax(leftheight, rightheight) + 1;
    } return nodeheight;
}

//a function to determine the balance factor
//uses the two height values of the left and right subtrees
//balance factor is used to determine rotations
int getBalanceFactor(Node *root){
    int leftheight, rightheight;
    if(root==NULL)
        return 0;
    if(root->leftchild==NULL)
        leftheight=0;
    else
        leftheight=1+height(root->leftchild);		//left height =1+root->left->height;
    if(root->rightchild==NULL)
        rightheight=0;
    else
        rightheight=1+height(root->rightchild); 	//right height =1+root->right->height;

    return (leftheight-rightheight);
}

//a function to determine if the tree is balanced or not
bool isBalanced(Node *root){
    //it is balanced if the difference between left subtree and right subtree is <=1
    int difference=abs(getBalanceFactor(root));
    if(difference<=1)
        return true;
    else
        return false;
}

//a function to help find the parent
Node* findParentHelper (int data, Node* node){
    //if leftChild exists check if it is equal to the given data value
    if (node->leftchild){
        if (node->leftchild->value == data){
            return node;
        }//if the data to compare is less than the value at the node, recursively call find parent helper
        else if (data < node->value) {
            return findParentHelper(data, node->leftchild);
        }
    }
    //if there is a rightchild check if the values are equal
    if ((node->rightchild)){
        if (node->rightchild->value == data){
            return node;
        }
    }
    //if right child does not exist, recursively call find parent helper
    if (data < node->value){
        return findParentHelper(data, node->leftchild);
    }
        //last resort: use function to help find parent
    else
        return findParentHelper(data, node->rightchild);
}

//the find parent function that takes into account special cases
Node *findParent(int data, Node *node) {
    if (node != NULL) {
        if (node->value == data)
            return node;
        if ((node->leftchild == NULL) && (node->rightchild == NULL))
            return NULL;

        return findParentHelper(data, node);
    }
}

//initially set deepest to null and the max depth to -1
Node *deepest = NULL;
int maxDepth = -1;

//a function to find a node using the node and depth of node in a tree
void find(Node *node, int depth){
    if(node!=NULL){
        find(node->leftchild, ++depth);
        if(depth>maxDepth){
            maxDepth = depth;
            deepest = node;
        } find(node->rightchild, depth);
    }
}

//a function to determine the deepest node
//uses the find node function
Node *deepestNode(Node *node){
    find(node, 0);
    return deepest;
}

//the function to do a left rotation
Node *rotateLeft(Node *node){
    Node *RC;
    RC=node->rightchild;
    node->rightchild=RC->leftchild;
    RC->leftchild=node;
    return RC;
}

//the function to do a right rotation
Node *rotateRight(Node *node){
    Node *LC;
    LC=node->leftchild;
    node->leftchild=LC->rightchild;
    LC->rightchild=node;
    return LC;
}

//the function to rotate left and then right
Node *rotateLeftRight(Node *node){
    Node *LC = node->leftchild;
    node->leftchild=rotateRight(LC);
    return rotateRight(node);
}

//the function to rotate right and then left
Node *rotateRightLeft(Node *node){
   Node *RC = node->rightchild;
   node->rightchild=rotateRight(RC);
   return rotateLeft(node);
}

//a function for pre order traversal
void preOrder(Node *root){
    if(root == NULL)
        return;
    printf("%d", root->value);
    preOrder(root->leftchild);
    preOrder(root->rightchild);
}

//the function that uses all rotation functions previously defined to rotate the tree into an AVL tree that is balanced
void rotation(Node *treeRoot){
        int balance;
        Node *parent = NULL, *grandparent = NULL;
        Node *root = NULL;
        while (1) {
            balance = isBalanced(treeRoot);
            if (balance < 2 && balance > -2) {
                printf("\nThe Binary Search Tree: ");
                preOrder(treeRoot);
                printf(" is balanced.");
                break;
            } else {
                printf("\nThe Binary Search Tree: ");
                preOrder(treeRoot);
                printf("is not balanced.");
            }
            deepestNode(treeRoot);
            parent = findParent(deepest->value, treeRoot);
            grandparent = findParent(parent->value, treeRoot);
            root = findParent(grandparent->value, treeRoot);
            if (balance > 1 && parent->value < root->leftchild->value)
                root->leftchild = rotateRight(grandparent);
            if (balance < -1 && parent->value > parent->rightchild->value)
                root->rightchild = rotateLeft(grandparent);
            if (balance > 1 && parent->value > root->leftchild->value)
                root->leftchild = rotateLeftRight(grandparent);
            if (balance < -1 && parent->value < root->rightchild->value)
                root->rightchild = rotateRightLeft(parent);
        }
    }

    //initialize the queue
queueNode *front = NULL, *back = NULL;
int count = 0;

int main(){
    //create a tree using value 12
    Tree* tree = createtree(12);
    //call the build function to create the tree
    buildTree(tree->root);
    //will rotate the tree accordingly
    rotation(tree->root);
}
