def solution(operations):
    import heapq
    answer = []
    hq = []
    for operation in operations:
        order, num = operation.split()
        if order == "I":
            heapq.heappush(hq,int(num))
        else:
            if hq:
                if num == '-1':
                    heapq.heappop(hq)
                else:
                    hq.sort()
                    hq.pop()
    hq.sort()
    if hq:
        answer.append(hq[-1])
        answer.append(hq[0])
    else:
        answer = [0,0]
    return answer