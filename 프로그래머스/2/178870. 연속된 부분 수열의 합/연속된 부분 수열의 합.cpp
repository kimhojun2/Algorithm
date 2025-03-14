#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int left = 0;
    int right = 0;
    int L = sequence.size();
    int min_length = L + 1;
    int sum = sequence[0];
    while (right < L) {
        if (sum == k) {
            if (right - left + 1 < min_length) {
                min_length = right - left + 1;
                answer = {left, right};
            }
            sum -= sequence[left++];
            sum += sequence[++right];
        } 
        else if (sum < k) {
            right++;
            if (right < L) {
                sum += sequence[right];
            }
        } 
        else {
            sum -= sequence[left++];
        }
    }
    return answer;
}