#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int idx=0;
    while(idx!=n){
        idx++;
        if(idx%2==1){
            answer+="수";
        }
        else{
            answer +="박";
        }
    }
    return answer;
}