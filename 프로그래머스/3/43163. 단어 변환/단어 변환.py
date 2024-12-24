def solution(begin, target, words):
    from collections import deque

    q=deque()
    q.append((begin,0))
    visited = set()
    answer = 0
    
    if target not in words:
        return 0
    
    def check(a,b):
        diff = 0
        for i in range(len(a)):
            if a[i] != b[i]:
                diff += 1
                if diff > 1:
                    return False

        return diff == 1
    
    while q:
        now, count = q.popleft()

        if now == target:
            answer = count

        for word in words:
            if word not in visited and check(now,word):
                visited.add(word)
                q.append((word,count+1))
    return answer