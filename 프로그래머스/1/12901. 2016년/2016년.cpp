#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<string> days = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
    int total = b;
    for(int month=1;month<a;month++){
        if(month == 2){
            total += 29;
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) { 
            total += 30;
        } 
        else {  
            total += 31;
        }
    }
     answer = days[total % 7];
    return answer;
}