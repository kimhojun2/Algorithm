word = list(input())

if word == [*reversed(word)]:
    print(1)
else:
    print(0)