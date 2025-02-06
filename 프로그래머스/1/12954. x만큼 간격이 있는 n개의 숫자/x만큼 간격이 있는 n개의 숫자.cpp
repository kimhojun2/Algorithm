#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    int now = x;
    while(n>0){
        answer.push_back(now);
        now += x;
        n--;
    }
    return answer;
}