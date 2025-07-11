import heapq

N = int(input())

tickets = []
lst = []
for i in range(N):
    row = list(input().split(' '))
    tickets += row
    for j in row:
        idx = j[0]
        num = int(j[2:])
        heapq.heappush(lst, (idx,num,j))


s = []
cnt = 0
now = heapq.heappop(lst)
while cnt < N*5:
    ticket = tickets[cnt]
    if now[2] == ticket:
        cnt += 1
        if not lst: break
        now = heapq.heappop(lst)
        continue

    if s and s[-1] == now[2]:
        if not lst: break
        now = heapq.heappop(lst)
        s.pop()
        continue

    else:
        cnt+=1
        s.append(ticket)

while s:
    remain = s.pop()
    if now[2] != remain: break
    if lst: now = heapq.heappop(lst)

print("GOOD" if not lst else "BAD")