word = input()

numbers = ('0', '1', '2', '3', '4', '5', '6', '7', '8', '9')
ROT13 = ''

for i in word:
    if i == ' ' or i in numbers:
        ROT13 += i

    elif 'A' <= i <= 'Z':
        ROT13 += chr((ord(i) - ord('A') + 13) % 26 + ord('A'))

    elif 'a' <= i <= 'z':
        ROT13 += chr((ord(i) - ord('a') + 13) % 26 + ord('a'))

print(ROT13)
