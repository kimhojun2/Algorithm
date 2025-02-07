#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int l = p.size();
    long long int_p = stoll(p);
    for(int i=0;i<=t.size()-l;i++){
        long long int_now = stoll(t.substr(i,l));
        if(int_now<=int_p){
            answer +=1;
        }
    }
    
    return answer;
}