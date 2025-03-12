#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(string A, string B){
    return A + B > B + A;
}


string solution(vector<int> numbers) {
    string answer = "";
    vector<string>lst;
    
    for(int number : numbers){
        lst.push_back(to_string(number));
    }
    
    sort(lst.begin(), lst.end(), compare);
    
    for(string number : lst){
        answer += number;
    }
    if (answer[0] == '0') {
        return "0";
    }
    
    
    return answer;
}