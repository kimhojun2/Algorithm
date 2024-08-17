def solution(park, routes):
    answer = []
    y = -1
    x = -1
    H = len(park)
    W = len(park[0])
    for i in range(H):
        for j in range(W):
            if park[i][j] == 'S':
                y = i
                x = j

    for route in routes:
        op, n = map(str, route.split())
        if op == 'N':
            flag = False
            for d in range(1, int(n)+1):
                if 0 > y - d or park[y-d][x] == 'X':
                    flag = True
            if not flag:
                y = y - int(n)
        elif op == 'S':
            flag = False
            for d in range(1, int(n)+1):
                if H <= y + d or park[y+d][x] == 'X':
                    flag = True
            if not flag:
                y = y + int(n)
            
        elif op == 'W':
            flag = False
            for d in range(1, int(n)+1):
                if 0 > x - d or park[y][x-d] == 'X':
                    flag = True
            if not flag:
                x = x - int(n)
            
        else:
            flag = False
            for d in range(1, int(n)+1):
                if W <= x + d or park[y][x+d] == 'X':
                    flag = True
            if not flag:
                x = x + int(n)
                
    return [y,x]