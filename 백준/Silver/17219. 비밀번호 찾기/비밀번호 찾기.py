import sys

input = sys.stdin.readline

N, M = map(int, input().split())
dic = {}

for i in range(N):
    s, p = input().split()
    dic[s] = p

for j in range(M):
    target = input().rstrip()
    print(dic[target])