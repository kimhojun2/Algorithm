#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include  <map>

# define LIMIT 1439

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int>dic;
    map<string, int>total;
    for(string record : records){
        string time,number,state;
        stringstream ss(record);
        ss >> time >> number >> state;
        int hour = stoi(time.substr(0,2));
        int min = stoi(time.substr(3,2));
        int change_time = hour*60 + min;
        if(state == "IN"){
            if(!change_time){
                change_time = 9999;
            }
            dic[number] = change_time;
        }
        else{
            int minus;
            if(dic[number] == 9999){
                minus = 0;
            }
            else{
                minus = dic[number];
            }
            total[number] += change_time - minus;
            dic[number] = 0;
        }
    }
    for(auto now : dic){
        if(now.second !=0){
            if(now.second == 9999){
                total[now.first] += LIMIT;
            }
            else{
                total[now.first] += (LIMIT - now.second);

                
            }
        }
    }
    
    for(auto now : total){
        if(now.second<=fees[0]){
            answer.push_back(fees[1]);
        }
        else{
            if((now.second-fees[0])%fees[2] !=0){
                answer.push_back(((now.second-fees[0]) / fees[2] + 1) * fees[3] + fees[1]);
            }
            else{
                answer.push_back(((now.second-fees[0]) / fees[2]) * fees[3] + fees[1]);
            }
            
        }
        cout << now.second<<" ";
    }
    
    return answer;
}