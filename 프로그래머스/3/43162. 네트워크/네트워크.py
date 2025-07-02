def solution(n, computers):
    answer = 0
    visited = [False for i in range(n)]
    for com in range(n):
        if visited[com] == False:
            BFS(n, computers, com, visited)
            answer += 1
    return answer

def BFS(n, computers, com, visited):
    from collections import deque
    visited[com] = True
    queue = deque()
    queue.append(com)
    while len(queue) != 0:
        com = queue.popleft()
        visited[com] = True
        for connect in range(n):
            if connect != com and computers[com][connect] == 1:
                if visited[connect] == False:
                    queue.append(connect)
