#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int xx = x;
    int y = 0;
    while(xx!=0){
        y+=(xx%10);
        xx/=10;
    }
    if(x%y!=0){
        answer = false;
    }
    return answer;
}