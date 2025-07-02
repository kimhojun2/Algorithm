def solution(money):
    L = len(money)
    
    # case 1: 첫 번째 집을 털고 → 두 번째 집과 마지막 집은 못 털어
    rob, skip = money[0], money[0]
    for i in range(2, L-1):
        rob, skip = money[i] + skip, max(rob, skip)
    case1 = max(rob, skip)
    
    # case 2: 첫 번째 집을 안 털고 → 마지막 집 털 수 있음
    rob, skip = money[1], 0
    for i in range(2, L):
        rob, skip = money[i] + skip, max(rob, skip)
    case2 = max(rob, skip)
    
    return max(case1, case2)
