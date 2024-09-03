def solution(s):
    S = []
    for i in s.split():
        S.append(int(i))
    S.sort()
    answer = ''
    answer = str(S.pop(0)) + ' ' + str(S.pop())
    return answer