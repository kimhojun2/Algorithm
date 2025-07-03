from collections import deque

dy = [0,0,1,-1]
dx = [1,-1,0,0]
q = deque()

def bfs(i,j,Y,X,land,visited):
    q.append((i,j))
    land[i][j] = 0
    cnt = 1
    garo = {j}
    while q:
        y, x = q.popleft()
        for d in range(4):
            ny, nx = y + dy[d], x + dx[d]
            if ny<0 or nx<0 or ny>=Y or nx>=X or land[ny][nx] == 0:
                continue
            land[ny][nx] = 0
            cnt += 1
            q.append((ny,nx))
            if d==0 or d==1:
                garo.add(nx)

    for idx in garo:
        visited[idx] += cnt
    
    return



def solution(land):
    answer = 0
    Y = len(land)
    X = len(land[0])
    
    visited = [0] * X
    
    for i in range(Y):
        for j in range(X):
            if land[i][j] == 1:
                bfs(i,j,Y,X,land,visited)
                
    answer = max(visited)
                
    return answer