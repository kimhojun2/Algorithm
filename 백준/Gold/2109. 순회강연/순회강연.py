import sys
import heapq

input = sys.stdin.readline

n = int(input())
q = []

for _ in range(n):
    p, d = map(int, input().split())
    heapq.heappush(q,(-1*p,d))

check = [0] * (10001)

ans = 0
while q:
    p, now_d = heapq.heappop(q)
    now_p = -1 * p

    stop = False
    for j in range(now_d,0,-1):
        if stop:
            break

        if check[j] == 0:
            check[j] = now_p
            ans += now_p
            stop = True

        else:
            if check[j] < now_p:
                ans -= check[j]
                check[j] = now_p
                ans += now_p
                stop = True

print(ans)