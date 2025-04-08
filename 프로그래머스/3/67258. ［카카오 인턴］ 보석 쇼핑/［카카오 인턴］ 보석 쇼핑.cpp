#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(vector<string> gems) {
    map<string, int> dic;
    for (const auto& gem : gems) {
        dic[gem] = 0;
    }
    int L = dic.size();
    int N = gems.size();
    vector<int> answer = {1, N};
    map<string, int> cl;
    int left = 0, right = 0;

    cl[gems[0]] = 1;

    while (left <= right && right < gems.size()) {
        if (cl.size() == L) {
            if ((right - left) < (answer[1] - answer[0])) {
                answer = {left + 1, right + 1};
            }
            cl[gems[left]]--;
            if (cl[gems[left]] == 0) {
                cl.erase(gems[left]);
            }
            left++;
        } else {
            right++;
            if (right == gems.size()) break;
            cl[gems[right]]++;
        }
    }

    return answer;
}
