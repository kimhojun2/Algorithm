def solution(board, h, w):
    
    answer = 0
    di = [0,0,1,-1]
    dj = [1,-1,0,0]
    
    for d in range(4):
        ny, nx = h + di[d], w + dj[d]
        if 0<= ny < len(board) and 0<= nx < len(board):
            if board[h][w] == board[ny][nx]:
                answer += 1
    print(board, h, w)
    return answer