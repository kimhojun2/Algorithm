import heapq

N, M = map(int, input().split())

dic = {}
check = [0] * (N+1)
for m in range(M):
    A, B = map(int, input().split())
    if A not in dic:
        dic[A] = []
    dic[A].append(B)
    check[B] += 1 

q = []
for i in range(1, N+1):
    if check[i] == 0:
        heapq.heappush(q, i)

ans = []
while q:
    now = heapq.heappop(q)
    ans.append(now)

    for next in dic.get(now, []): 
        check[next] -= 1 

        if check[next] == 0: 
            heapq.heappush(q, next)

print(*ans)
