#include <iostream>
using namespace std;

int N;
char leftChild[26];
char rightChild[26];

void preorder(char cur) {
    if (cur == '.') return;
    cout << cur;
    preorder(leftChild[cur - 'A']);
    preorder(rightChild[cur - 'A']);
}

void inorder(char cur) {
    if (cur == '.') return;
    inorder(leftChild[cur - 'A']);
    cout << cur;
    inorder(rightChild[cur - 'A']);
}

void postorder(char cur) {
    if (cur == '.') return;
    postorder(leftChild[cur - 'A']);
    postorder(rightChild[cur - 'A']);
    cout << cur;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        char parent, l, r;
        cin >> parent >> l >> r;
        leftChild[parent - 'A'] = l;
        rightChild[parent - 'A'] = r;
    }

    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    cout << '\n';

    return 0;
}
