import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())

sadari = {}
baam = {}
for n in range(N):
    x, y = map(int, input().split())
    sadari[x] = y

for m in range(M):
    u, v = map(int, input().split())
    baam[u] = v

q = deque()
q.append(1)
visited = [-1] * 101
visited[1] = 0

while q:
    now = q.popleft()
    
    for i in range(1, 7):
        Next = now + i
        if Next > 100:
            continue
        if Next in sadari:
            Next = sadari[Next]
        elif Next in baam:
            Next = baam[Next]
        
        if visited[Next] == -1 or visited[Next] > visited[now] + 1:
            visited[Next] = visited[now] + 1
            q.append(Next)
        
        if Next == 100:
            break

print(visited[100])
