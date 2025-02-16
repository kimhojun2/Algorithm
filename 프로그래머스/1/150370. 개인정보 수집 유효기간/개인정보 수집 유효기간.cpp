#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;



vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int>m;
    int today_year = stoi(today.substr(0,4));
    int today_month = stoi(today.substr(5,2));
    int today_day = stoi(today.substr(8,2));
    for(auto term : terms){
        char type;
        string month;
        istringstream iss(term);
        iss >> type >> month;
        m[type] = stoi(month);
    }
    
    for(int i=0;i<privacies.size();i++){
        int year,month,day;
        char type;
        year = stoi(privacies[i].substr(0,4));
        month = stoi(privacies[i].substr(5,2));
        day = stoi(privacies[i].substr(8,2));
        type = privacies[i][11];
        month += m[type];
        while(1){
            if(month>12){
                year+=1;
                month-=12;
                continue;
            }
            break;
        }
        
        if(today_year > year){
            answer.push_back(i+1);
            continue;
        }
        else{
            if(today_year == year && today_month>month){
                answer.push_back(i+1);
                continue;
            }
            else{
                if(today_year == year && today_month == month && today_day >= day){
                    answer.push_back(i+1);
                    continue;
                }
            }
        }
        
        cout << i+1<<" "<<year<<" "<< month<<" "<<day<<" "<<type<<'\n';
        
    }
    
    return answer;
}