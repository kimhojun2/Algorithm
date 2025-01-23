k=int(input())
c=int(input())

for i in range(c):
    m,n=map(int,input().split())
    if m<n:
        if n-m-1>=k-n+1:
            print(0)
        else:
            print(1)
    elif m>n:
        if m-n-1>k-m+1:
            print(0)
        else:
            print(1)
    else:
        print(1)