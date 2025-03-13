#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

set<int> lst;

bool prime(int n){
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;   
}


void check(int& answer, string numbers, string now, vector<bool>& visited){
    
    for(int i=0;i<numbers.size();i++){
        if(visited[i]==true) continue;
        int num = stoi(now+numbers[i]);
        visited[i] = true;
        if(prime(num)&&lst.find(num) == lst.end()){
            lst.insert(num);
            answer++;
        }
        check(answer,numbers,now+numbers[i],visited);
        visited[i] = false;
    }
    
}


int solution(string numbers) {
    int answer = 0;
    vector<bool>visited(numbers.size(), false);
    check(answer, numbers, "", visited);
    return answer;
}