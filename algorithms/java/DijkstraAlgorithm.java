import java.util.*; 
import java.lang.*; 
import java.io.*; 
  
class ShortestPath { 
 
    static final int V = 9; //Number of vertices in graph
    int minDistance(int dist[], Boolean sptSet[]) 
    { 
        // Initialize min value 
        int min = Integer.MAX_VALUE, min_index = -1; 
  
        for (int v = 0; v < V; v++) 
            if (sptSet[v] == false && dist[v] <= min) { 
                min = dist[v]; 
                min_index = v; 
            } 
  
        return min_index; 
    } 
  
    void printSolution(int dist[], int n) 
    { 
        System.out.println("Vertex   Distance from Source"); 
        for (int i = 0; i < V; i++) 
            System.out.println(i + " ======> " + dist[i]); 
    } 
  
    // Implements Dijkstra's algorithm
    void dijkstra(int graph[][], int src) 
    { 
        int dist[] = new int[V]; // dist[i] will hold the shortest distance from source to i 
  
        Boolean sptSet[] = new Boolean[V]; 
  
        for (int i = 0; i < V; i++) { 
            dist[i] = Integer.MAX_VALUE; 
            sptSet[i] = false; 
        } 
  
        // Distance of source vertex from itself is 0 
        dist[src] = 0; 
  
        //Shortest path for all vertices 
        for (int count = 0; count < V - 1; count++) { 
             
            int u = minDistance(dist, sptSet); 
  
            // Mark the picked vertex
            sptSet[u] = true; 
  
            // Update dist value of the adjacent vertices of the picked vertex. 
            for (int v = 0; v < V; v++) 
   
                if (!sptSet[v] && graph[u][v] != 0 &&  
                   dist[u] != Integer.MAX_VALUE && dist[u] + graph[u][v] < dist[v]) 
                    dist[v] = dist[u] + graph[u][v]; 
        } 
  
        // print the constructed distance array 
        printSolution(dist, V); 
    } 
  
    public static void main(String[] args) 
    { 
        /* creating the graph */
        int graph[][] = new int[][] { { 0, 4, 3, 0, 0, 0, 0, 6, 0 }, 
                                      { 4, 0, 8, 0, 0, 0, 0, 12, 0 }, 
                                      { 3, 8, 0, 7, 0, 2, 0, 0, 2 }, 
                                      { 0, 0, 7, 0, 9, 12, 0, 0, 0 }, 
                                      { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                                      { 0, 0, 2, 12, 10, 0, 2, 0, 0 }, 
                                      { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                                      { 6, 12, 0, 0, 0, 0, 1, 0, 5 }, 
                                      { 0, 0, 2, 0, 0, 0, 6, 5, 0 } }; 
        ShortestPath t = new ShortestPath(); 
        t.dijkstra(graph, 0); 
    } 
} 
