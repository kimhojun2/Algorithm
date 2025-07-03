def solution(name):
    answer = 0
    L = len(name)

    for ch in name:
        move = ord(ch) - ord('A')
        answer += min(move, 26 - move)

    min_move = L - 1
    for i in range(L):
        next_idx = i + 1
        
        while next_idx < L and name[next_idx] == 'A':
            next_idx += 1
            
        move = i + L - next_idx + min(i, L - next_idx)
        min_move = min(min_move, move)

    answer += min_move
    return answer