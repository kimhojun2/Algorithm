#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int, int> left = {3, 0};
    pair<int, int> right = {3, 2};
    map<int, pair<int, int>> keypad = {
        {1, {0, 0}}, {2, {0, 1}}, {3, {0, 2}},
        {4, {1, 0}}, {5, {1, 1}}, {6, {1, 2}},
        {7, {2, 0}}, {8, {2, 1}}, {9, {2, 2}},
        {0, {3, 1}}
    };

    for (auto now : numbers) {
        pair<int, int> target = keypad[now];
        int targetY = target.first;
        int targetX = target.second;
        if (now == 1 || now == 4 || now == 7) {
            answer += 'L';
            left = keypad[now];
        } else if (now == 3 || now == 6 || now == 9) {
            answer += 'R';
            right = keypad[now];
        } else {
            int distL = abs(left.first - targetY) + abs(left.second - targetX);
            int distR = abs(right.first - targetY) + abs(right.second - targetX);
            if (distL < distR) {
                answer += 'L';
                left = keypad[now];
            } else if (distR < distL) {
                answer += 'R';
                right = keypad[now];
            } else {
                if (hand == "right") {
                    answer += 'R';
                    right = keypad[now];
                } else {
                    answer += 'L';
                    left = keypad[now];
                }
            }
        }
    }
    return answer;
}
