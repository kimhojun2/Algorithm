#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    long long R = left / n;
    long long C = left % n;

    while (left <= right) {
        answer.push_back(max(R, C) + 1);

        C++;
        if (C == n) {
            C = 0;
            R++;
        }

        left++;
    }

    return answer;
}
