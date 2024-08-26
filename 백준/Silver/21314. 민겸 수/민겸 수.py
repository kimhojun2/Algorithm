l = input()
M = ''
m = ''
last = ''
nu = ''
for i in l:
    if i == 'M':
        if last == '':
            last = 'M'
            nu = '1'
        elif last == 'M':
            nu += '0'

    else:
        if last == '':
            m += '5'
            M += '5'

        else:
            last = ''
            m = m + nu + '5'
            nu += '0'
            M = M + str(int(nu)*5)
            nu = ''

if last == 'M':
    m += nu
    for i in nu:
        if i == '0':
            i = '1'
        M += i
print(M)
print(m)