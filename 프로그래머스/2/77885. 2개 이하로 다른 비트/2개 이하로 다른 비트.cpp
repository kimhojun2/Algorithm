#include <vector>
#include <iostream>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for (long long number : numbers) {
        if (number % 2 == 0) { 
            answer.push_back(number + 1);
        } else {
            long long lowbit = number & -number;
            long long next = number + lowbit;
            long long new_bit = (next ^ number) >> 2;
            answer.push_back(next | new_bit);
        }
    }
    return answer;
}
