#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    int idx = col - 1;

    sort(data.begin(), data.end(), [idx](const vector<int>& a, const vector<int>& b) {
        if (a[idx] == b[idx]) return a[0] > b[0];
        return a[idx] < b[idx];
    });

    for (int i = row_begin - 1; i < row_end; i++) {
        int s = 0;
        for (int j = 0; j < data[i].size(); j++) {
            s += data[i][j] % (i + 1);
        }
        answer ^= s;
    }

    return answer;
}
