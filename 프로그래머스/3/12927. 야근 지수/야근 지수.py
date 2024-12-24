def solution(n, works):
    import heapq
    
    answer = 0
    max_heap = [-x for x in works]
    heapq.heapify(max_heap)
    
    while n>0:
        now = -1 * heapq.heappop(max_heap)
        if now != 0:
            next_value = -1*(now-1)
        else:
            next_value = 0
        heapq.heappush(max_heap,next_value)
        n -= 1
    
    for i in max_heap:
        answer += (-1*i) * (-1*i)
    return answer