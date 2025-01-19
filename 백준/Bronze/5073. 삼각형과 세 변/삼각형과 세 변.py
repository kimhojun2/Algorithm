while True:
    shape = list(map(int, input().split()))
    shape.sort()
    a,b,c = shape[0],shape[1],shape[2]
    if a==0 and b==0 and c==0:
        break

    if c >= a+b:
        print("Invalid")

    elif a==b and b==c and c==a:
        print("Equilateral")
    elif a != b and b!= c and a!=c:
        print("Scalene")
    else:
        print("Isosceles")

