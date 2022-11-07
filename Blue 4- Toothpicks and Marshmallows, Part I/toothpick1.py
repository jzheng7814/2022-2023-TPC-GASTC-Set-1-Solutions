N, M = [int(i) for i in input().split()]

vis = [False for i in range(N + 1)]
graph = [[] for i in range(N + 1)]
c = 0

def dfs(s):
    if vis[s]:
        return
    
    vis[s] = True

    for i in graph[s]:
        dfs(i)

for i in range(M):
    a, b = [int(j) for j in input().split()]

    graph[a].append(b)
    graph[b].append(a)

for i in range(1, N + 1):
    if not vis[i]:
        dfs(i)
        c += 1

print(c)