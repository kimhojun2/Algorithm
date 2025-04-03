#include <iostream>
#include <vector>
using namespace std;

bool col[12];          
bool diag1[24];         
bool diag2[24];

int answer = 0;

void check(int n, int row) {
    if (row == n) {
        answer++;
        return;
    }

    for (int j = 0; j < n; j++) {
        if (col[j] || diag1[row + j] || diag2[row - j + n - 1])
            continue;

        col[j] = diag1[row + j] = diag2[row - j + n - 1] = true;
        check(n, row + 1);
        col[j] = diag1[row + j] = diag2[row - j + n - 1] = false;
    }
}

int solution(int n) {
    answer = 0;
    check(n, 0);
    return answer;
}
