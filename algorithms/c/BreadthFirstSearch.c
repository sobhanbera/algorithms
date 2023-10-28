#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the graph
struct Node
{
    int data;
    struct Node *next;
};

// Structure to represent a queue for BFS
struct Queue
{
    int front, rear;
    int capacity; // Add a capacity field
    int *array;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a queue
struct Queue *createQueue(int capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    queue->array = (int *)malloc(capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue)
{
    return queue->front == -1;
}

// Function to enqueue an element
void enqueue(struct Queue *queue, int item)
{
    if (queue->rear == queue->capacity - 1)
    { // Use queue->capacity
        printf("Queue is full!\n");
        return;
    }
    if (queue->front == -1)
        queue->front = 0;
    queue->rear++;
    queue->array[queue->rear] = item;
}

// Function to dequeue an element
int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front++;
    if (queue->front > queue->rear)
        queue->front = queue->rear = -1;
    return item;
}

// Function to perform Breadth First Search
void BFS(int **graph, int vertices, int startVertex)
{
    struct Queue *queue = createQueue(vertices);
    int visited[vertices];
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;
    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (!isEmpty(queue))
    {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        for (int i = 0; i < vertices; i++)
        {
            if (graph[currentVertex][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }
}

int main()
{
    int vertices = 6;

    // Allocate memory for an array of pointers
    int *graph = (int *)malloc(vertices * sizeof(int *));

    // Allocate memory for each row of the adjacency matrix
    for (int i = 0; i < vertices; i++)
    {
        graph[i] = (int *)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++)
            graph[i][j] = 0;
    }

    // Adding edges to the graph
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][3] = 1;
    graph[1][4] = 1;
    graph[2][4] = 1;
    graph[3][5] = 1;
    graph[4][5] = 1;

    printf("Breadth First Traversal starting from vertex 0:\n");
    BFS(graph, vertices, 0);

    return 0;
}

