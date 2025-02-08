#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

string solution(string X, string Y) {
    string answer = "-1";
    vector<int> numbers(10, 0);
    priority_queue<int> pq;

    for (int i = 0; i < X.size(); i++) {
        int now = X[i] - '0';
        numbers[now]++;
    }

    for (int i = 0; i < Y.size(); i++) {
        int now = Y[i] - '0'; 
        if (numbers[now] > 0) {
            numbers[now]--;
            pq.push(now);
        }
    }

    if (pq.empty()) {
        return "-1";
    }

    answer = "";
    while (!pq.empty()) {
        answer += to_string(pq.top()); 
        pq.pop();
    }

    if (answer[0] == '0') {
        return "0";
    }

    return answer;
}
