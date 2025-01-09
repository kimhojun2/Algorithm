def solution(want, number, discount):
    answer = 0 
    dic = {}
    L = len(want)
    for i in range(L):
        dic[want[i]] = number[i]
    
    l = len(discount)
    for i in range(l):
        if i+10 > l:
            continue
        new_dic = dic.copy()
        nbp = False
        for j in range(i,i+10):
            now = discount[j]
            if now not in dic:
                continue
            new_dic[now] -= 1

        for v in new_dic.values():
            if v > 0:
                nbp = True
                break
        
        if not nbp:
            answer += 1
            
            
    
    return answer