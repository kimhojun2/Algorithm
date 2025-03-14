#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;


string solution(string number, int k) {
    string result = "";
    int n = number.size();
    int to_remove = k; // 제거해야 할 개수

    for (char c : number) {
        while (!result.empty() && to_remove > 0 && result.back() < c) {
            result.pop_back();
            to_remove--;
        }
        result.push_back(c);
    }

    // 아직 k개를 다 제거하지 못했다면 뒤에서 자르기
    result = result.substr(0, n - k);
    return result;
}
