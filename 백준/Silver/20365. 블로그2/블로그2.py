N = int(input())
color = input()
B = 0
R = 0
last = color[0]
for i in range(N-1):
    now = color[i+1]
    if i == N-2:
        if now =='B':
            B +=1
        else:
            R +=1
    if now == 'B':
        if last == 'B':
            continue
        else:
            R += 1
            last = 'B'
    else:
        if last == 'R':
            continue
        else:
            B += 1
            last = 'R'


print(min(B,R) + 1)

