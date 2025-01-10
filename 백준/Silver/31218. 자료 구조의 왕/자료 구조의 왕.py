from collections import deque

n, m, Q = map(int, input().split())

green = [[0]*m for _ in range(n)]

def qry1(qry):
    cut = 0
    dy,dx,Y,X = qry
    y,x = Y-1,X-1
    if green[y][x] == 1:
        return cut

    q = deque()
    q.append((y,x))
    green[y][x] = 1
    cut += 1
    while q:
        y, x = q.popleft()
        ny, nx = y+dy, x+dx
        if ny<0 or nx <0 or ny >=n or nx>=m:
            return cut

        if green[ny][nx] == 0:
            green[ny][nx] = 1
            q.append((ny,nx))
            cut += 1

    return cut


def qry2(qry):
    y,x = qry
    print(green[y-1][x-1])




cnt = n*m
for q in range(Q):
    qry = list(map(int, input().split()))
    if qry[0] == 1:
        cut = qry1(qry[1:])
        cnt -= cut
    elif qry[0] == 2:
        qry2(qry[1:])
    else:
        print(cnt)
