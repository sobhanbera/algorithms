#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a graph
struct Graph {
    int vertices;
    int** adjMatrix;
    int* visited;
};

// Function to create a new graph with 'vertices' number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
        graph->visited[i] = 0;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int source, int destination) {
    graph->adjMatrix[source][destination] = 1;
    // For an undirected graph, you can add the reverse edge as well
    // graph->adjMatrix[destination][source] = 1;
}

// Depth-First Search traversal
void DFS(struct Graph* graph, int vertex) {
    printf("%d ", vertex);
    graph->visited[vertex] = 1;

    for (int i = 0; i < graph->vertices; i++) {
        if (!graph->visited[i] && graph->adjMatrix[vertex][i]) {
            DFS(graph, i);
        }
    }
}

int main() {
    struct Graph* graph = createGraph(6);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);

    printf("Depth-First Search starting from vertex 0:\n");
    DFS(graph, 0);

    return 0;
}
