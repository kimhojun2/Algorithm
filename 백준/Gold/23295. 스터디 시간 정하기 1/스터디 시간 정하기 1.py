import sys
input = sys.stdin.readline

N, T = map(int, input().split())

times = [0] * 100002
last = 0
for _ in range(N):
    K = int(input())
    for _ in range(K):
        s, e = map(int, input().split())
        times[s] += 1
        times[e] -= 1
        last = max(last,e)

init = 0
for i in range(T):
    times[i+1] += times[i]
    init += times[i]

MAX = init
start, end = 0,T
for i in range(T, last+1):
    times[i+1] += times[i]
    init += times[i] - times[i-T]
    if MAX < init:
        start, end, MAX = i - T + 1, i+1, init


print(start, end)
