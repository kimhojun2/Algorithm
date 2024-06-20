check = [0 for i in range(26)]
word = input()

for i in word:
    check[ord(i) - 97] += 1

print(*check)

