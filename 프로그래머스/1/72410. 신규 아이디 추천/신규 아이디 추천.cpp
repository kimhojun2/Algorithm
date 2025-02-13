#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    int idx = 0;
    int sol = 0;
    while(idx<new_id.size()){
        //1단계
        if('A'<=new_id[idx] && new_id[idx]<='Z'){
            new_id[idx] += 32;
        }
        //2단계
        if (('0' <= new_id[idx] && new_id[idx] <= '9') ||
            new_id[idx] == '-' || new_id[idx] == '_' || new_id[idx] == '.' ||
            ('a' <= new_id[idx] && new_id[idx] <= 'z')) idx++;
        else{
            new_id.erase(idx,1);
        }
    }
    //3단계
    for (int i = 0; i < new_id.length() - 1 ; ) {
        if (new_id[i] == '.' && new_id[i+1] == '.') {
            new_id.erase(new_id.begin() + i);
            continue;
        }
        i++;    
    }
    //4단계
    if(new_id[0] == '.'){
        new_id.erase(0,1);
    }
    if(new_id[new_id.size()-1] == '.'){
        new_id.erase(new_id.size()-1,1);
    }
    //5단계
    if(new_id.size()==0){
        new_id = 'a';
    }
    //6단계
    if(new_id.size()>=16){
        new_id.erase(15);
        if(new_id[14]=='.'){
            new_id.erase(new_id.size()-1,1);
        }
    }
    //7단계
    while(1){
        if(new_id.size()<=2){
            new_id +=new_id[new_id.size()-1];
            continue;
        }
        break;
    }
    answer = new_id;
    return answer;
}