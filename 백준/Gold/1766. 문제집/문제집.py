from collections import deque
import heapq


def problems():
    q = []

    for i in range(N):
        if indegree[i] == 0:
            heapq.heappush(q,i)


    while q:
        now = heapq.heappop(q)
        print(now+1, end=" ")

        for next in graph[now]:
            indegree[next] -= 1
            if indegree[next] == 0:
                heapq.heappush(q, next)

N, M = map(int, input().split())

graph = [[] for _ in range(N)]
indegree = [0] * N

for m in range(M):
    A, B = map(int, input().split())
    graph[A-1].append(B-1)
    indegree[B-1] += 1

problems()