def BFS(graph, s):
    # Mark all the vertices as not visited
    visited = [False] * len(graph)

    queue = []
    queue.append(s)
    visited[s] = True

    while queue:
        s = queue.pop(0)
        print(s, end=" ")

        for i in graph[s]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True


def addEdges(graph, u, v):
    graph[u].append(v)
    graph[v].append(u)


if __name__ == "__main__":
    n = int(input("Enter the number of nodes: "))
    m = int(input("Enter the number of edges: "))
    graph = [[] for node in range(n)]
    for edge in range(m):
        start, end = map(int, input().split())
        addEdges(graph, start, end)
    BFS(graph, 0)
