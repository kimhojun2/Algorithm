import sys
input = sys.stdin.readline

n = int(input().rstrip())
l = list(map(int,input().rstrip().split()))
l.sort()

m = -int(1e9)

if len(l)%2==0:
    for i in range(n//2):
        m = max(l[i]+l[n-i-1],m)
    print(m)
else:
    for i in range((n-1)//2):
        m = max(l[i]+l[n-i-2],m)
    print(max(m,l[-1]))