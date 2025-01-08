def solution(k, tangerine):
    import heapq
    answer = 0
    dic = {}
    for i in tangerine:
        if i in dic:
            dic[i] += 1
        else:
            dic[i] = 1
    lst = []
    for value in dic.values():
        heapq.heappush(lst,-1*value)

    while k>0 and lst:
        now = heapq.heappop(lst)
        if k < -1*now:
            answer += 1
            break
        k += now
        answer += 1

    
    return answer