from collections import deque

def solution(n, computers):
    answer = 0
    visited = [0] * n     
    # di = [1,-1,0,0]
    # dj = [0,0,1,-1]
    
    def bfs(i):
        q = deque()
        q.append(i)
        visited[i] = 1
        
        while q:
            y = q.popleft()
            
            for c in range(n):
                if computers[y][c] == 1 and visited[c] == 0:
                    visited[c] = 1
                    q.append(c)
        
        return
        
    
    for i in range(n):
        if visited[i] == 0:
            answer +=1
            bfs(i)
            
            
    return answer