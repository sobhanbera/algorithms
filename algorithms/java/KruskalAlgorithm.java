import java.util.*;

// We use Disjoint Set Union to help us in constructing the MST, and checking cycles in MST
public class KruskalAlgorithm {
    static class Edge implements Comparable<Edge> {
        int src, dest, weight;
        public Edge(int src, int dest, int weight) {
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }
        
        @Override
        public int compareTo(Edge edge) {
            // Function to help sort the edges
            return this.weight - edge.weight;
        }
    }
    
    public static int findParent(int src, int[] parents) {
        // If the parent of any vertex is the vertex itself
        // then this is the parent of the vertex of the current edge
        if(parents[src] == src) {
            return src;
        } else {
            parents[src] = findParent(parents[src], parents);
            return parents[src];
        }
    }
    
    public static void union(int src, int dest, int[] parents, int[] size) {
        // Find the parent of both the vertices in the current edge, and merge the disjoint sets
        src = findParent(src, parents);
        dest = findParent(dest, parents);
        if(size[src] > size[dest]) {
            parents[dest] = src;
            size[src] += size[dest];
        } else {
            parents[src] = dest;
            size[dest] += size[src];
        }
    }
    
    public static boolean isCyclic(int src, int dest, int[] parents) {
        return findParent(src, parents) == findParent(dest, parents);
    }
    
    public static void kruskalAlgo(int nodes, int numEdges, Edge[] edges, int[][] graph) {
        // This array is to store the minimum spanning tree formed
        int[][] minSpanTree = new int[graph.length][graph.length];
        // Sorting all the edges
        Arrays.sort(edges);
        
        // Parents and size array for creating disjoint sets
        int[] parents = new int[nodes+1];
        int[] size = new int[nodes+1];
        for(int i = 1; i < graph.length; i++) {
            parents[i] = i;
            size[i] = i;
        }
        
        int edgeCounter = 0;
        int edgedTaken = 1;
        
        // For connnecting all nodes, we must have at-least nodes-1 edges
        while(edgedTaken <= nodes - 1) {
            
            Edge e = edges[edgeCounter];
            edgeCounter++;
            
            // Do not include if, cycle is created
            if(isCyclic(e.src, e.dest, parents))
                continue;
            
            union(findParent(e.src, parents), findParent(e.dest, parents), parents, size);
            minSpanTree[e.src][e.dest] = e.weight;
            edgedTaken++;
        }
        
        /* Displaying Tree*/
        System.out.println("The minimum spanning tree is as follows:");
        for(int i=1; i<minSpanTree.length; i++) {
            for(int j=0; j<minSpanTree.length; j++) {
                if(minSpanTree[i][j] != 0)
                    System.out.println(i + " " + j + " " + minSpanTree[i][j]);
            }
        }
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the number of nodes: ");
        int nodes = in.nextInt();
        int[][] graph = new int[nodes+1][nodes+1];
        System.out.print("Enter the number of edges: ");
        int numEdges = in.nextInt();
        Edge[] edges = new Edge[numEdges];
        
        for(int i = 0; i<numEdges; i++) {
            System.out.println("Enter source, destination and weight:");
            int src = in.nextInt(), dest = in.nextInt(), weight = in.nextInt();
            
            // This is a check to remove multiple edges between two nodes
            // Edge with least weight remains
            if(graph[src][dest] == 0 || weight < graph[src][dest]) {
                // The graph is considered undirected
                graph[src][dest] = weight;
                graph[dest][src] = weight;
                
                edges[i] = new Edge(src, dest, weight);
            }
            
        }
        kruskalAlgo(nodes, numEdges, edges, graph);
    }
}