#include <string>
#include <vector>

using namespace std;

void check(int idx, vector<int> &numbers, int total, int target, int &answer) {
    if (idx == numbers.size()) {
        if (total == target) {
            answer++;
        }
        return;
    }

    for (int i = 0; i < 2; i++) {
        if (i == 0) {
            check(idx + 1, numbers, total + numbers[idx], target, answer);
        } else {
            check(idx + 1, numbers, total - numbers[idx], target, answer);
        }
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    check(0, numbers, 0, target, answer);
    return answer;
}