#include <stdio.h>
#include <stdlib.h>

#define VISITED 1
#define UNVISITED 0

typedef struct _node{
    int data;
    struct _node *next;
}Node;

typedef struct _list{
    Node *first, *last;
}List;


int **readAdjMatrix(FILE *input, int *numberOfVertices) {
    fscanf(input, "%d", numberOfVertices);
    fgetc(input);
    int **matrix = (int **)malloc((*numberOfVertices)*sizeof(int*));
    for(int i=0; i<(*numberOfVertices); i++){
        matrix[i] = (int *)malloc((*numberOfVertices)*sizeof(int*));
        for(int j=0; j<(*numberOfVertices); j++){
            fscanf(input,"%d", &matrix[i][j]);
            fgetc(input);
        }
    }
    return matrix;
}

void printMatrix(int **adjMatrix, int numberOfVertices) {
    for(int i=0; i<numberOfVertices; i++){
        for (int j = 0; j <numberOfVertices ; ++j) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void addLast(List *list, int value) {
    if(list->first == NULL){
        list->first = (Node *)malloc(sizeof(Node));
        list->first->data = value;
        list->first->next = NULL;
        list->last = list->first;
    }else {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;
        list->last->next = newNode;
        list->last = newNode;
    }
}

List *getListFromMatrix(int **matrix, int noOfVertices) {
    List *adjList = (List *)malloc(noOfVertices * sizeof(List));
    for(int i=0; i<noOfVertices; i++){
        adjList[i].first = NULL;
        adjList[i].last = NULL;
        for (int j = 0; j <noOfVertices ; ++j) {
            if(matrix[i][j])
                addLast(&adjList[i], j+1);
        }
    }
    return adjList;
}


void printAdjList(List *pList, int noOfVertices) {
    Node *currNode;
    for(int i=0; i<noOfVertices; i++){
        printf("%d: ", i+1);
        currNode = pList[i].first;
        while(currNode != NULL){
            printf("%d ", currNode->data);
            currNode = currNode->next;
        }
        printf("\n");
    }
}

int **getMatrixFromList(List *pList, int noOfVertices) {
    int **matrix = (int **)malloc(noOfVertices * sizeof(int *));
    for (int i = 0; i <noOfVertices ; ++i) {
        matrix[i] = (int *)malloc(noOfVertices * sizeof(int));
        Node *currentNode = pList[i].first;
        while(currentNode){
            matrix[i][currentNode->data - 1] = 1;
            currentNode = currentNode->next;
        }
    }
    for (int i = 0; i <noOfVertices ; ++i) {
        for (int j = 0; j <noOfVertices ; ++j) {
            if(matrix[i][j] != 1)
                matrix[i][j] = 0;
        }

    }
    return matrix;
}

void enqueue(List *list, int value) {
    if(list->first == NULL){
        list->first = (Node *)malloc(sizeof(Node));
        list->first->data = value;
        list->first->next = NULL;
        list->last = list->first;
    } else {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;
        list->last->next = newNode;
        list->last = newNode;
    }
}

int dequeue(List *list) {
    int data;
    if(list->first) {
        data = list->first->data;
        list->first = list->first->next;
    }

    if(list->first == NULL)
        list->last = NULL;

    return data;
}

int getNumberOfNeighborsOfVertex(List *pList, int indexNode) {
    int count = 0;
    Node *currentNeighbor = pList[indexNode].first;
    while(currentNeighbor){
        count++;
        currentNeighbor = currentNeighbor->next;
    }
    return count;
}

int *getAllNeighborsOfVertex(List *pList, int indexNode, int nrOfNeighbors) {
    int *neighbors = (int *)malloc(nrOfNeighbors * sizeof(int));
    int i = 0;
    Node *currentNeighbor = pList[indexNode].first;
    while(currentNeighbor){
        neighbors[i] = currentNeighbor->data - 1;
        i++;
        currentNeighbor = currentNeighbor->next;
    }
    return neighbors;
}

void bfs(int startNode, List *adjList, int noOfVertices) {
    startNode--;
    int *visited = (int *) malloc(noOfVertices * sizeof(int));
    int i, v, w;

    for (i = 0; i < noOfVertices; i++) {
        visited[i] = UNVISITED;
    }
    List *queue = (List *)malloc(sizeof(List));
    queue->first = queue->last = NULL;
    enqueue(queue, startNode);
    visited[startNode] = VISITED;
    printf("%d ", startNode + 1);

    while (queue->first != NULL) {
        v = dequeue(queue);

        int nrOfNeighbors = getNumberOfNeighborsOfVertex(adjList, v);
        int *neighbors = getAllNeighborsOfVertex(adjList, v, nrOfNeighbors);
        for (i = 0; i < nrOfNeighbors; i++) {
            w = neighbors[i];
            if (visited[w] == UNVISITED) {
                printf("%d ", w + 1);
                enqueue(queue, w);
                visited[w] = VISITED;
            }
        }
    }

    printf("\nBFS ended\n\n");
}
void dfsRec(int v, int *visited, List *adjList) {
    int i;
    visited[v] = VISITED;
    int nrOfNeighbors = getNumberOfNeighborsOfVertex(adjList, v);
    int *neighbors = getAllNeighborsOfVertex(adjList, v, nrOfNeighbors);
    printf("%d ", v + 1);
    for (i = 0; i < nrOfNeighbors; i++) {
        int w = neighbors[i];
        if (visited[w] == UNVISITED) {
            dfsRec(w, visited, adjList);
        }
    }
}

void dfsRecurs(int startNode, List *adjList, int noOfVertices) {
    startNode--;
    printf("DFS recursive started\n");
    int *visited = (int *) malloc(noOfVertices * sizeof(int));
    int i;

    for (i = 0; i < noOfVertices; i++) {
        visited[i] = UNVISITED;
    }
    dfsRec(startNode, visited, adjList);
    printf("\nDFS recursive ended\n\n");
}
int main() {
    FILE *input;
    input = fopen("input.txt", "r");
    int numberOfVertices;
    int **adjMatrix = readAdjMatrix(input, &numberOfVertices);

    List *adjList = getListFromMatrix(adjMatrix, numberOfVertices);
    printf("\n\nThe adjacency list from given adjacency matrix:\n");
    printAdjList(adjList, numberOfVertices);
    printf("\n\nThe given matrix from the computed adjacency list:\n");
    adjMatrix = getMatrixFromList(adjList, numberOfVertices);
    printMatrix(adjMatrix, numberOfVertices);
    printf("\n\nBFS on the resulted adjacency list:\n");
    bfs(1,adjList, numberOfVertices);
    dfsRecurs(1,adjList,numberOfVertices);


    return 0;
}
