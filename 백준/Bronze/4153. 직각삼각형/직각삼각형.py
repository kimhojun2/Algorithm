def check(a,b,c):
    s1, s2, s3 = sorted([a, b, c], reverse=True)

    if s1**2 == s2**2 + s3**2:
        return 1

    return 0

while True:
    a,b,c = map(int, input().split())
    if a==0 and b==0 and c==0:
        break

    if check(a,b,c):
        print("right")
    else:
        print("wrong")