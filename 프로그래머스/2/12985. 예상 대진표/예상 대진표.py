def solution(n,a,b):
    answer = 1
    front = min(a,b)
    back = max(a,b)
    while True:
        if back - front == 1 and front %2 == 1:
            break
            
        front = front//2 + front%2
        back = back//2 +back%2
        answer += 1
    

    return answer