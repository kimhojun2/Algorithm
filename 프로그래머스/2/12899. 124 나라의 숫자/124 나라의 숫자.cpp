#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

string solution(int n) {
    string answer = "";
    
    map<int, char> dic = {
        {1, '1'},
        {2, '2'},
        {0, '4'}
    };
    
    while (n > 0) {
        answer += dic[(n%3)];
        if ((n%3) == 0) {
            n = n / 3 - 1;
        } else {
            n /= 3;
        }
        
    }
    reverse(answer.begin(),answer.end());
    
    return answer;
}
