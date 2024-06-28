import sys
from collections import deque

input = sys.stdin.readline
n, m = map(int, input().split())
g = [[] for _ in range(n + 1)]
ret = []

for _ in range(m):
	a, b = map(int, input().split())
	g[b].append(a) # a가 b를 신뢰한다는 것은 결국 b를 해킹하면 a를 해킹할 수 있다는 것이기 때문에 b에 a를 추가

def bfs(i):
	d = deque([i])
	visit = [0] * (n + 1)
	visit[i] = 1
	cnt = 1
	while d:
		i = d.popleft()
		for j in g[i]:
			if not visit[j]:
				d.append(j)
				visit[j] = 1
				cnt += 1
	return cnt

max_cnt = 1
for i in range(1, n + 1): # 컴퓨터 건건으로 탐색
	cnt = bfs(i)
	if cnt > max_cnt: # 최장 길이 갱신
		max_cnt = cnt
		ret = [] # ret 배열 초기화
		ret.append(i)
	elif cnt == max_cnt:
		ret.append(i)

print(*ret)