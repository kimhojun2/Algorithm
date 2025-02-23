#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string change(string city){
    string chci = "";
    for(int i=0; i<city.size();i++){
        if(city[i]>='a' && city[i]<='z'){
            chci += toupper(city[i]);
        }
        else{
            chci += city[i];
        }
    }
    return chci;
}


int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if(cacheSize==0){
        return 5* cities.size();
    }
    vector<string> cash;
    for (int i = 0; i < cities.size(); i++) {
        string now = change(cities[i]);
        
        auto it = find(cash.begin(), cash.end(), now);
        if (it != cash.end()) {
            cash.erase(it);
            answer +=1;
        }
        else{
            if(cash.size()==cacheSize){
                cash.erase(cash.begin());
            }
            answer += 5;
        }   
        cash.push_back(now);
        
    }
    return answer;
}