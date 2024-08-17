def solution(name, yearning, photo):
    answer = []
    dic = {}
    
    for n in range(len(name)):
        dic[name[n]] = yearning[n]
        
    for i in range(len(photo)):
        total = 0

        for ph in photo[i]:
            if ph in dic:
                total += dic[ph]
                
        answer.append(total)
            
    return answer