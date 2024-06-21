n = int(input())
x,y = input().split("*")
for _ in range(n):
    file = input()
    if len(file) < len(x)+len(y):
        print("NE")
    elif file[:len(x)] == x and file[-len(y):] == y:
        print("DA")
    else:
        print("NE")