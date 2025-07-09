from collections import deque

def bfs(A, B):
    q = deque()
    q.append(A)
    visited = [-1] *(N+1)
    visited[A] = 0
    while q:
        now = q.popleft()

        for next in range(N+1):
            if distacne[now][next] == 1 and visited[next] == -1:
                visited[next] = visited[now] + 1
                q.append(next)

    print(visited[B])


N = int(input())
distacne = [[-1] *(N+1) for _ in range(N+1)]
graph = []
for n in range(N):
    s, e = map(int, input().split())
    graph.append([s,e,n+1])

sgraph = sorted(graph, key=lambda x:(x[0],x[1]))

for i in range(N):
    for j in range(i+1,N):
        if sgraph[i][1] >= sgraph[j][0]:
            distacne[sgraph[i][2]][sgraph[j][2]] = 1
            distacne[sgraph[j][2]][sgraph[i][2]] = 1

Q = int(input())
questions = [list(map(int, input().split())) for _ in range(Q)]

for A,B in questions:
    bfs(A,B)
