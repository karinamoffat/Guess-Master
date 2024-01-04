//Karina Moffat

#include <stdio.h>
#include <stdlib.h>

typedef enum state {GREEN, GREY, RED} VertexState;

//initialize the vertex structure
struct Vertex{
    int		    label;		// only single character label for vertex
    VertexState	visited;	// state while search underway
};

typedef struct Vertex vertex;

//initialize the node structure
struct Node{
    vertex *vertex;
    struct queueNode *next;
};

typedef struct Node node;

//head and tail of node initially set to NULL
node* head = NULL;
node* tail = NULL;

//a function to enqueue a given vertex of the graph
void enqueue (vertex* Vertex){
    node *new = (node*)malloc (sizeof(node));
    new->vertex = Vertex;

    if (tail != NULL) {
        tail->next = new;
    }
    tail = new;

    if (head == NULL)
        head = new;
}

//a function to dequeue the first vertex (head) in the graph
vertex* dequeue (){
    vertex *temp = NULL;
    if (head){
        temp = head->vertex;
        head = head->next;
    }
    return temp;
}

//initialize an integer to keep track of the number of vertices in the graph
int		counter = 0;

//initialize an array of pointers to point to the stored vertex values
vertex	*Vertices[10];

//a function to reset the visited vertices
void reset (){
    int	i;
    for (i=0; i<counter; i++)
        Vertices[i]->visited = GREEN;
}

//a function to add a vertex into the graph
//will set the label of the new vertex equal to the value passed through the function
void addVertex(int label){
    vertex *newVertex = (vertex*)malloc(sizeof(vertex*));
    newVertex->label = label;
    newVertex->visited = GREEN;
    Vertices[counter++] = newVertex;
}

//initialize an array to keep track of the edge information
int		adjMatrix[10][10];

//a function to add an edge to the graph, will pass the start and end values through the function
void addEdge (int start, int end) {
    /*if the start value is greater than/equal to zero but less than the count, and end value is greater than/equal
    to zero and less than/equal to the count, set the value in the edge array at the start row, end column to 1.
     This will represent adding an edge to the graph*/
    if (start >= 0 && start < counter && end >= 0 && end <= counter)
        adjMatrix[start][end] = 1;
}

//a function to make the graph (graph shown in assignment)
void makeGraph (){
    for (int i = 0; i < 7; i++){
        addVertex(i);
    }
    addEdge(0,1);
    addEdge(0,2);
    addEdge(1,3);
    addEdge(4,1);
    addEdge(5,2);
    addEdge(5,6);
    addEdge(6,0);
    addEdge(6,4);
}

vertex *unvisitedVertex(vertex *Vertex){
    int i;
    for (i=0; i<counter; i++)	{
        if	(adjMatrix[Vertex->label][i] > 0 && (Vertices[i]->visited == GREEN))	{//bc the row # always corresponds to the
            //value of the vertex
            return Vertices[i];
        }
    }
    return NULL;
}

//a function to implement the breadth first traversal
int breadthFirstCheck (vertex *Vertex){
    int		i;
    vertex	*notVisitedVertex;

    //put the first node as visited
    Vertices[Vertex->label]->visited = GREY;

    //add the vertex to the queue
    enqueue(Vertex);

    //while the head exists (have not reached the end of the graph, graph is not empty)...
    while(head != NULL) {
        //find the vertex value at the front of the queue
        vertex *tempVertex;
        tempVertex= dequeue();

        //if there is no adjacent vertex, add it to the queue
        while((notVisitedVertex = unvisitedVertex(tempVertex)) != NULL) {
            notVisitedVertex->visited = GREY;
            enqueue(notVisitedVertex);
        }
    }

    int check = 1;
    for (i=0; i<counter; i++) {
        if (Vertices[i]->visited == GREEN) {
            check = 0;
        }
    }

    reset ();
    head = NULL, tail = NULL;
    return check;
}

//a function to identify the mother vertex in the given graph
int *Mothvex(){
    static int array[10];
    for (int i = 0; i < counter; i++){
        array[i] = 11;
    }
    int j = 0;
    for (int i = 0; i < counter; i++){
        if (breadthFirstCheck(Vertices[i])){
            array[j] = Vertices[i]->label;
            j++;
        }
    }
    return array;
}

int main(){
    printf("In this graph the mother vertex is ");

    makeGraph();
    int *array = Mothvex();

    for (int i = 0; i < counter; i++){
        if (array[i] == 11) break;
        printf ("%d ", array[i]);
    }

}