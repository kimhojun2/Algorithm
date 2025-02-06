#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long now = num;
    while(now != 1){
        if(answer>500){
            answer = -1;
            break;
        }
        if(now%2==0){
            now/=2;
        }
        else{
            now = now * 3 + 1;
        }
        answer++;
    }
    return answer;
}