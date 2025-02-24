#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for(int i=1; i<phone_book.size();i++){
        string now = phone_book[i];
        string before = phone_book[i-1];
        if(now.substr(0,before.size()) == before){
            answer = false;
            break;
        }
    }
    return answer;
}