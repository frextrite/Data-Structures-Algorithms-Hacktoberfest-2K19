from collections import defaultdict

def DFS(v, visited):
    visited[v-1] = True
    print(v, end=" ")
    for u in graph[v]:
        if visited[u-1] == False:
            DFS(u, visited)

if __name__ == "__main__":
    #n = number of nodes, m = number of edges
    n, m = map(int, input().split())
    
    graph = defaultdict(list)

    #Input format: adjancey matrix of graph
    for _ in range(m):
        i, j = map(int, input().split())
        graph[i].append(j)
        graph[j].append(i)
    print(graph)

    visited = [False] * n

    DFS(1, visited)

#Analysis:

#Time Complexity: O(V + E)


