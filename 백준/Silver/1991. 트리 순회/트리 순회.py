N = int(input())

tree = {}

for i in range(N):
    node, left, right = input().split()

    tree[node] = [left, right]


def preorder(nd):
    if nd != '.':
        print(nd, end='')
        preorder(tree[nd][0])
        preorder(tree[nd][1])


def inorder(nd):
    if nd != '.':
        inorder(tree[nd][0])
        print(nd, end='')
        inorder(tree[nd][1])

def postorder(nd):
    if nd != '.':
        postorder(tree[nd][0])
        postorder(tree[nd][1])
        print(nd, end='')

preorder('A')
print()
inorder('A')
print()
postorder('A')