def solution(arr1, arr2):
    N = len(arr1)
    M = len(arr1[0])
    K = len(arr2[0])
    answer = [[0]*K for _ in range(N)]
    for i in range(N):
        for j in range(K):
            for k in range(M):
                answer[i][j] += arr1[i][k] * arr2[k][j]
                
    return answer