import sys

input = sys.stdin.readline

T = int(input())

for tc in range(T):
    a,b,c = map(int, input().split())
    print(min(a,b,c))
