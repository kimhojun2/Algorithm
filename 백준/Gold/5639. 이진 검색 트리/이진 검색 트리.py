import sys
sys.setrecursionlimit(10 ** 9)
input = sys.stdin.readline

node = []
while True:
    try:
        node.append(int(sys.stdin.readline()))
    except:
        break


def BST(start, end):
    if start > end:
        return
    mid = end + 1
    for i in range(start + 1, end + 1):
        if node[i] > node[start]:
            mid = i
            break
    BST(start + 1, mid - 1)
    BST(mid, end)
    print(node[start])


BST(0, len(node) - 1)
