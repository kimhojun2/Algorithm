def solution(cacheSize, cities):
    from collections import deque
    answer = 0
    cashe = deque(maxlen=cacheSize)
    L = cacheSize
    if L==0:
        return 5*len(cities)
    for cityy in cities:
        city = cityy.lower()
        if city in cashe:
            answer +=1
            cashe.remove(city)
            cashe.append(city)
        else:
            answer +=5
            cashe.append(city)
                
    return answer