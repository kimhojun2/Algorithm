#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int day = (100 - progresses[0]) / speeds[0] + ((100 - progresses[0]) % speeds[0] != 0 ? 1 : 0);
    int cnt = 0;
    for(int i=0;i<progresses.size();i++){
        int now = progresses[i] + speeds[i] * day;
        if(now >=100){
            cnt++;
            continue;
        }
        else{
            answer.push_back(cnt);
            cnt=1;
            day += (100-now) / speeds[i];
            if((100-now) % speeds[i] != 0) day++;
        }
    }
    answer.push_back(cnt);
    return answer;
}