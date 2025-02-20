#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;


// map 복사하는 방법
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> dic;
    for (int i = 0; i < want.size(); i++) {
        dic[want[i]] = number[i];
    }

    int l = discount.size();
    for (int i = 0; i <= l - 10; i++) {
        map<string, int> tmp(dic);
        bool tf = true;

        for (int j = i; j < i + 10; j++) {
            tmp[discount[j]]--;
        }

        for (const auto& c : tmp) {
            if (c.second > 0) { 
                tf = false;
                break;
            }
        }
        if (tf) {
            answer++;
        }
    }

    return answer;
}
