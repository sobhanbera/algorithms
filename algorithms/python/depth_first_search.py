def dfs(graph, start):
    visited = set()
    stack = [start]
    
    while stack:
        node = stack.pop()
        if node not in visited:
            visited.add(node)
            print(node, end=' ') 
            stack.extend(neighbor for neighbor in graph[node] if neighbor not in visited)

            
        
    

def addEdges(graph, u, v):
    graph[u].append(v)
    graph[v].append(u)


def main():
    n = int(input("Enter the number of nodes: "))
    m = int(input("Enter the number of edges: "))
    graph = [[] for node in range(n)]
    for edge in range(m):
        start, end = map(int, input().split())
        addEdges(graph, start, end)
    dfs(graph, 0)
    
if __name__ == '__main__':
    main() 
