def solution(people, limit):
    people.sort(reverse=True)  
    start, end = 0, len(people) - 1
    answer = 0
    
    while start <= end:
        if people[start] + people[end] <= limit: 
            end -= 1  
        start += 1 
        answer += 1  
    
    return answer
