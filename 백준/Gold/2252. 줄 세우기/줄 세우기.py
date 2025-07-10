from collections import defaultdict
import heapq
import sys
input = sys.stdin.readline

def line():
    ans =[]
    q= []
    for i in range(1,N+1):
        if indgree[i] == 0:
            heapq.heappush(q,i)

    while q:
        now = q.pop()
        ans.append(now)

        for np in graph[now]:
            indgree[np] -= 1
            if indgree[np] == 0:
                heapq.heappush(q,np)


    return ans


N, M = map(int, input().split())

graph = defaultdict(list)
indgree = [0] * (N + 1)

for m in range(M):
    A, B = map(int, input().split())
    graph[A].append(B)
    indgree[B] += 1

answer = line()
print(*answer)