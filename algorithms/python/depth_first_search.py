# Define a recursive Depth-First Search (DFS) function to traverse a graph and print nodes in DFS order.
def dfs(graph, node, visited):
    # Mark the current node as visited.
    visited.add(node)
    # Print the current node (you can replace this with any desired action).
    print(node, end=' ')

    # Recursively visit all unvisited neighbors of the current node.
    for neighbor in graph[node]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited)

# Define a function to add edges to the graph.
def addEdges(graph, u, v):
    graph[u].append(v)
    graph[v].append(u)

# Main function to input the graph and start DFS.
def main():
    # Input the number of nodes.
    n = int(input("Enter the number of nodes: "))
    # Input the number of edges.
    m = int(input("Enter the number of edges: "))
    
    # Create an empty graph represented as an adjacency list.
    graph = [[] for node in range(n)]
    
    # Assuming nodes are numbered from 0 to n-1
    # Input edges and add them to the graph.
    for edge in range(m):
        a=int(input("Enter first node of the edge: "))
        b=int(input("Enter second node of the edge: "))
        if (a<0 or a>=n) or (b<0 or b>=n):
            print("Invalid Input!")
            return
        addEdges(graph, a, b)
    
    # Create a set to keep track of visited nodes.
    visited = set()
    
    # Perform DFS from each unvisited node.
    for node in range(n):
        if node not in visited:
            dfs(graph, node, visited)

# Entry point of the program.
if __name__ == '__main__':
    main()
