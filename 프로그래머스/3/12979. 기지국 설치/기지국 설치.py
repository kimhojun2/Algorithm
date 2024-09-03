def solution(n, stations, w):
    answer = 0
    p = 0
    limit = 2*w+1
    for station in stations:
        left = station - w
        right = station + w
        
        if p < left -1:
            need = left - p - 1
            answer += (need + limit - 1) // limit
        
        p = right
        
    if p < n:
        need = n - p
        answer += (need + limit - 1) // limit
            
    return answer