def solution(s):
    answer = True
    openn = 0
    for i in s:
        if i == '(':
            openn += 1
        else:
            if openn > 0:
                openn -= 1
            else:
                answer = False
                break
    if openn != 0:
        answer = False
    return answer