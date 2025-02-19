#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    unordered_set<string> dic;
    string end = "";

    for (int i = 0; i < words.size(); i++) {
        string now = words[i];

        if (i != 0 && end.back() != now.front()) {
            answer = {i % n + 1, (i / n) + 1};
            break;
        }

        if (dic.find(now) != dic.end()) {
            answer = {i % n + 1, (i / n) + 1};
            break;
        }

        dic.insert(now);
        end = now;
    }

    return answer;
}
