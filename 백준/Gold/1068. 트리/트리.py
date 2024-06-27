from collections import deque


def build_tree(N, lst):
    nodes = {}
    root = None
    for i in range(N):
        if lst[i] == -1:
            root = i
        else:
            node = lst[i]
            if node in nodes:
                nodes[node].append(i)
            else:
                nodes[node] = [i]
    return nodes, root


def delete_subtree(nodes, delete_node):
    q = deque([delete_node])
    while q:
        now = q.popleft()
        if now in nodes:
            for child in nodes[now]:
                q.append(child)
            del nodes[now]
    # 부모의 자식 리스트에서도 삭제할 노드를 제거해야 함
    for key in nodes:
        if delete_node in nodes[key]:
            nodes[key].remove(delete_node)
    return nodes


def count_leaf_nodes(nodes, root, delete_node):
    if root == delete_node:
        return 0

    leaf_count = 0
    q = deque([root])

    while q:
        node = q.popleft()
        if node not in nodes or len(nodes[node]) == 0:
            leaf_count += 1
        else:
            for child in nodes[node]:
                if child != delete_node:
                    q.append(child)
            # 모든 자식이 삭제 노드인 경우 리프 노드로 간주
            if all(child == delete_node for child in nodes[node]):
                leaf_count += 1

    return leaf_count


# 입력 처리 부분
N = int(input())
lst = list(map(int, input().split()))
delete_node = int(input())

# 트리 구성
nodes, root = build_tree(N, lst)

# 노드 삭제
nodes = delete_subtree(nodes, delete_node)

# 리프 노드 계산
leaf_count = count_leaf_nodes(nodes, root, delete_node)

print(leaf_count)
