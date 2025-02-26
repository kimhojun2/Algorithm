#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    map<string,int>dic;
    int total_str1 = 0;
    for(int i=0;i<str1.size()-1;i++){
        string new_word = "";
        for(int j=0;j<2;j++){
            char c = str1[i+j];
            if(c>='a' && c<='z'){
                new_word += c;
            }
            else if (c>='A' && c<='Z'){
                new_word += tolower(c);
            }
        }
        if(new_word.size() !=2) continue;
        dic[new_word] += 1;
        total_str1++;
    }
    
    int total_str2 = 0;
    int intersection_cnt =0;
    for(int i=0;i<str2.size()-1;i++){
        string new_word = "";
        for(int j=0;j<2;j++){
            char c = str2[i+j];
            if(c>='a' && c<='z'){
                new_word += c;
            }
            else if (c>='A' && c<='Z'){
                new_word += tolower(c);
            }
        }
        if(new_word.size() !=2) continue;
        total_str2++;
        if(dic[new_word]>0){
            intersection_cnt++;
            dic[new_word]--;
        }
        
    }
    
    cout << total_str1 << '\n';
    cout << total_str2 << '\n';
    cout << intersection_cnt << '\n';
    cout << total_str1+total_str2-intersection_cnt << '\n';
    if(total_str1+total_str2-intersection_cnt == 0){
        answer = 65536;
    }
    else{
        answer = (intersection_cnt * 65536 / (total_str1+total_str2-intersection_cnt));
    }
    return answer;
}