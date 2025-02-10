#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int check = 0;
    for(int now:section){
        if(now>check){
            answer++;
            check = now+m-1;
        }
    }
    return answer;
}