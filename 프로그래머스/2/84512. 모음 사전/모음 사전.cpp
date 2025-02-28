#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string word) {
    int answer = 0;
    map<char, int> dic = {
        {'A',0},
        {'E',1},
        {'I',2},
        {'O',3},
        {'U',4},
    };
    int diff[5] = { 781, 156, 31, 6, 1};
    for(int i=0;i<size(word);i++){
        answer += diff[i]*dic[word[i]] + 1;
    }
    return answer;
}