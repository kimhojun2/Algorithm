import sys
from collections import deque
import heapq

input = sys.stdin.readline

N, K = map(int, input().split())
gold = {n:0 for n in range(1,N+1)}
silver = {n:0 for n in range(1,N+1)}
bronze = {n:0 for n in range(1,N+1)}
ranking = []


for n in range(N):
    nation, g, s, b = map(int, input().split())
    heapq.heappush(ranking,(-1*g,-1*s,-1*b, nation))

now_g = -1
now_s = -1
now_b = -1
rank = 0
same = 0
while ranking:
    ng,ns,nb,nn = heapq.heappop(ranking)
    Ng = -1* ng
    Ns = -1 * ns
    Nb = -1 * nb

    if now_g == Ng and now_s == Ns and npw_b == Nb:
        same += 1

    else:
        if same:
            rank += same
            same = 0
        else:
            rank += 1
        now_g = Ng
        now_s = Ns
        npw_b = Nb

    if nn == K:
        print(rank)
        break