from collections import defaultdict, deque

def order():
    q = deque()
    ans = []
    for i in range(1,N+1):
        if indgree[i] == 0:
            q.append(i)
            ans.append(i)

    while q:
        now = q.popleft()

        for singer in graph[now]:
            indgree[singer] -= 1
            if indgree[singer] == 0:
                ans.append(singer)
                q.append(singer)


    return ans if len(ans) == N else 0


N, M = map(int, input().split())

graph = defaultdict(list)
indgree = [0]*(N+1)

for m in range(M):
    lst = list(map(int, input().split()))
    E = lst[0]
    for e in range(1, E):
        A, B = lst[e], lst[e+1]
        graph[A].append(B)
        indgree[B] += 1


answer = order()
if not answer:
    print(0)
else:
    for a in answer:
        print(a)