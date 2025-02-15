#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int total_time = stoi(video_len.substr(0,2)) *60 + stoi(video_len.substr(3,5));
    int pos_time = stoi(pos.substr(0,2)) *60 + stoi(pos.substr(3,5));
    int ops_time = stoi(op_start.substr(0,2)) *60 + stoi(op_start.substr(3,5));
    int ope_time = stoi(op_end.substr(0,2)) *60 + stoi(op_end.substr(3,5));
    // cout << total_time << " "<< pos_time<<" "<<ops_time<<" "<<ope_time;
    for(auto order : commands){
        if(pos_time>=ops_time && pos_time<=ope_time){
            pos_time = ope_time;
        }
        if(order=="next"){
            if(total_time-pos_time<10){
                pos_time = total_time;
            }
            else{
                pos_time +=10;
            }
        }
        else{
            if(pos_time<10){
                pos_time = 0;
            }
            else{
                pos_time -=10;
            }
        }
    }
    if(pos_time>=ops_time && pos_time<=ope_time){
        pos_time = ope_time;
    }
    
    string min = to_string(pos_time /60);
    string sec = to_string(pos_time%60);
    if((pos_time /60)<10){
        min = "0"+min;
    }
    if((pos_time%60)<10){
        sec = '0'+sec;
    }
    
    
    answer += (min + ':'+sec);
    
    return answer;
}