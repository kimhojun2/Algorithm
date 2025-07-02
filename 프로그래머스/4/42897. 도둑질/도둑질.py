def solution(money):
    answer = 0
    L = len(money)
    lst1 = [[0]*2 for _ in range(L)]
    lst1[0] = [money[0],money[0]]
    # 처음 집 방문
    for i in range(1,L):
        if i == 1 or i == L-1:
            lst1[i][1] = max(lst1[i-1])
        else:
            lst1[i][0] = money[i] + lst1[i-1][1]
            lst1[i][1] = max(lst1[i-1])
            
    lst2 = [[0]*2 for _ in range(L)]
    # 처음 집 안방문
    for i in range(1,L):
        lst2[i][0] = money[i] + lst2[i-1][1]
        lst2[i][1] = max(lst2[i-1])
    
    answer = max(max(lst1[L-1]), max(lst2[L-1]))
    
    return answer