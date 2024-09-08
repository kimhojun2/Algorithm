import sys
import heapq

input = sys.stdin.readline

N = int(input())
check = [0] * (1001)
q = []
for i in range(N):
    d, w = map(int, input().split())
    heapq.heappush(q,(-1 * w,d))

ans = 0
while q:
    w, now_d = heapq.heappop(q)
    now_w = -1 * w

    stop = False
    for j in range(now_d, 0, -1):
        if stop:
            break

        if check[j] == 0:
            check[j] = now_w
            ans += now_w
            stop = True
        else:
            if check[j] < now_w:
                ans -= check[j]
                check[j] = now_w
                ans += now_w
                stop = True


print(ans)