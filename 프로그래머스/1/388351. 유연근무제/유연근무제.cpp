#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for(int i=0;i<timelogs.size();i++){
        int limit = schedules[i];
        int hours = limit / 100;
        int minutes = limit % 100;
        minutes += 10;
        if (minutes >= 60) {
            hours += 1;
            minutes -= 60;
        }
        limit = hours * 100 + minutes;
        int today = startday;
        bool tf = true;
        for(int j=0;j<timelogs[i].size();j++){
            int now = timelogs[i][j];
            if(now>limit && (today!=6 && today !=7)){
                tf = false;
                break;
            }
            today = (today % 7) + 1;
        }
        if(tf){
            answer++;
        }
    }
    return answer;
}