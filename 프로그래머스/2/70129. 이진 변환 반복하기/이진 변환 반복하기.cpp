#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2,0);
    while(s.size()>1){
        //1단계
        int cnt = 0;
        string first = "";
        for(auto now : s){
            if(now=='0'){
                answer[1]++;
                continue;
            }
            first+=now;
        }
        //2단계
        int L = first.size();
        deque<int>q;
        while(L>0){
            q.push_back(L%2);
            L /= 2;
        }
        string second ="";
        while(!q.empty()){
            second += to_string(q.front());
            q.pop_front();
        }
        s = second;
        answer[0]++;
    }
    return answer;
}