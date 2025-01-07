def solution(targets):
    answer = 0
    targets.sort(key=lambda x:x[1])
    last_end = 0
    for start, end in targets:
        if start >= last_end:
            last_end = end
            answer+=1
        # print(start, end)
    
    return answer