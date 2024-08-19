def solution(n):
    answer = []
    
    def hanoi(start, x, end, n):
        if n == 1:
            answer.append([start, x])
        else:
            hanoi(start,end,x,n-1)
            hanoi(start,x,end,1)
            hanoi(end,x,start,n-1)
            
    hanoi(1,3,2,n)
    
    return answer
