#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<char, int>dic = {
        {'A',1},{'B',2},{'C',3},{'D',4},{'E',5},{'F',6},{'G',7},{'H',8},{'I',9},{'J',10},
        {'K',11},{'L',12},{'M',13},{'N',14},{'O',15},{'P',16},{'Q',17},{'R',18},{'S',19},{'T',20},
        {'U',21},{'V',22},{'W',23},{'X',24},{'Y',25},{'Z',26},
    };
    
    map<string,int> new_dic;
    int idx=0;
    int temp_idx = idx;
    int num = 27;
    while(idx < msg.size()-1){
        string now = msg.substr(temp_idx, 2);
        temp_idx++;
        while(temp_idx < msg.size()){
            // 문자열이 새로운 단어장에 없다면
            if(new_dic.find(now) == new_dic.end()){
                if(now.size()==2){  // 문자열의 길이가 2이면
                    answer.push_back(dic[now[0]]);  // 알파벳을 추가하고
                    new_dic.insert({now, num}); // 새로운 단어장에 현재 단어 저장
                    num++;   // 단어장 인덱스 증가
                    }
                else{   // 문자열의 길이가 2가 넘는다면
                    // 새로운 단어장에서 단어의 길이보다 1작은 값의 인덱스를 찾아서 저장하고
                    answer.push_back(new_dic[now.substr(0,now.length()-1)]);
                    // 새로운 단어장의 지금의 단어를 저장
                    new_dic.insert({now, num});
                    //단어장 인덱스 증가
                    num++;
                }
                break;
            }
            else{
                temp_idx++;
                now += msg[temp_idx];
            }
        }
        if(temp_idx <= msg.size()-1){
            idx = temp_idx;
        }
        else break;
    }
    cout << idx <<" ";
    cout << temp_idx;
    if(temp_idx ==  msg.size()-1){
        answer.push_back(dic[msg[temp_idx]]);
    }
    else{
        string new_new = msg.substr(idx);
        answer.push_back(new_dic[msg.substr(idx)]);
        cout << new_new;
    }
    
    return answer;
}