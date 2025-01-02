def solution(s):
    answer = ''
    flag = True
    for i in s:
        if i ==' ':
            flag = True
        else:
            if flag == True:
                if 'a'<=i<='z':
                    i = i.upper()

            else:
                if 'A'<=i<='Z':
                    i = i.lower()
            flag = False

        answer += i

    return answer

