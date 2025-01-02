def solution(s):
    answer = [0, 0]

    while s != '1':
        new = ''
        for i in s:
            if i == '0':
                answer[1] += 1
            else:
                new += '1'

        bin_new = len(new)
        arr = []
        while bin_new>0:
            arr.append(str(bin_new % 2))
            bin_new //= 2

        arr.reverse()
        s = ''
        for i in arr:
            s += i

        answer[0] += 1

    return answer
