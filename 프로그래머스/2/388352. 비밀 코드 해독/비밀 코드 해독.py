def solution(n, q, ans):
    from itertools import combinations
    answer = 0
    candidates = list(combinations(range(1,n+1), 5))
    Q = len(q)
    
    for candidate in candidates:
        correct = True
        for h, a in zip(q, ans):
            if len(set(candidate) & set(h)) != a:
                correct = False
                break
        if correct:
            answer+=1
    
    return answer