def solution(friends, gifts):
    print(friends)
    f = len(friends)
    arr = [[0] * f for _ in range(f)]
    dic = {}
    
    for i in range(f):
        dic[friends[i]] = i 
        
    for gift in gifts:
        se, re = map(str, gift.split())
        y, x = dic[se], dic[re]
        arr[y][x] += 1
        
    result = [0]*f
    
    for i in range(f):
        for j in range(f):
            if i == j:
                continue
                
            if arr[i][j] > arr[j][i]:
                result[i] += 1
                
            elif arr[i][j] == arr[j][i]:
                t1 = sum(arr[i])
                t2 = sum(arr[j])
                
                for k in range(f):
                    t1 -= arr[k][i]
                    t2 -= arr[k][j]
                    
                if t1 > t2:
                    result[i] += 1
                    
    return max(result)