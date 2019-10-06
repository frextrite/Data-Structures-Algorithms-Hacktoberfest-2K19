# topological_sort_in_python

def iterative_dfs_improved(graph, start):
    seen = set()  # efficient set to look up nodes in
    path = []     # there was no good reason for this to be an argument in your code
    q = [start]
    while q:
        v = q.pop()   # no reason not to pop from the end, where it's fast
        if v not in seen:
            seen.add(v)
            path.append(v)
            q.extend(graph[v]) # this will add the nodes in a slightly different order
                               # if you want the same order, use reversed(graph[v])

    return path
    
    
    # added file topological-sorting, in python
