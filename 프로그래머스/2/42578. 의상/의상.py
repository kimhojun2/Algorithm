def solution(clothes):
    dic = {}
    for cloth in clothes:
        a, b = cloth
        if b not in dic:
            dic[b] = 1
        else:
            dic[b] += 1

    answer = 1
    for value in dic.values():
        answer *= (value + 1)

    return answer - 1 
