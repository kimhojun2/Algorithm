R, C, M = map(int, input().split())

if M == 0:
    print(0)

else:
    graph = [[-1] * C for _ in range(R)]            # graph가 필요한가? ---> 필요하다
    sharks = []
    die = []

    for i in range(M):
        r,c,s,d,z = map(int, input().split())
        graph[r-1][c-1] = i
        sharks.append([r-1,c-1,s,d,z])

    # dy = [-1,1,0,0]
    # dx = [0,0,1,-1]

    def shark_move(p,s,d):

        np = p
        ns = s
        nd = d

        while ns != 0:
            if nd == 1:
                if np-ns <= 0:
                    ns -= np
                    np = 0
                    nd = 2
                else:
                    np -= ns
                    ns = 0
                    nd = 1

            elif nd == 2:
                if np + ns >= R-1:
                    ns -= (R-1-np)
                    np = R-1
                    nd = 1
                else:
                    np += ns
                    ns = 0
                    nd = 2
            elif nd == 3:
                if np + ns >= C-1:
                    ns -= (C-1-np)
                    np = C-1
                    nd = 4
                else:
                    np += ns
                    ns = 0
                    nd = 3
            else:
                if np-ns <= 0:
                    ns -= np
                    np = 0
                    nd = 3
                else:
                    np -= ns
                    ns = 0
                    nd = 4

        return np, nd


    idx = 0
    ans = 0
    while idx < C:
        # 사람이 잡을 상어가 있는지 확인
        for y in range(R):
            if graph[y][idx] != -1:
                shark_idx = graph[y][idx]
                die.append(shark_idx)
                ans += sharks[shark_idx][4]
                sharks[shark_idx] = 0
                graph[y][idx] = -1
                break



        new_graph = [[-1] * C for _ in range(R)]  # 새로운 맵
        new_sharks = [0] * M

        for i in range(M):
            # 상어들 움직이기
            if sharks[i] == 0: continue
            y,x,s,d,z = sharks[i]
            graph[y][x] = -1
            if d == 1 or d == 2:
                ny, nd = shark_move(y,s,d)
                nx = x
            else:
                nx, nd = shark_move(x,s,d)
                ny = y
            # 상어끼리 잡아먹기
            if new_graph[ny][nx] != -1:
                prev_idx = new_graph[ny][nx]
                pz = new_sharks[prev_idx][4]
                if pz > z: continue
                else:
                    new_sharks[prev_idx] = 0
            new_graph[ny][nx] = i
            new_sharks[i] = [ny, nx, s, nd, z]

        graph = new_graph
        sharks = new_sharks
        idx += 1


    print(ans)

