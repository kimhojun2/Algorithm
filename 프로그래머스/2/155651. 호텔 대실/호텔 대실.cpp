#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(const vector<string>& A, const vector<string>& B){
    
    return A[0]<B[0];
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<int> rooms;
    // vector<pair<int,int>> times;
    sort(book_time.begin(), book_time.end(), compare);
    for(vector<string> now : book_time){
        int start = stoi(now[0].substr(0,2))*60+stoi(now[0].substr(3));
        int end = stoi(now[1].substr(0,2))*60+stoi(now[1].substr(3))+10;
        bool tf = false;
        for(int i =0;i<rooms.size();i++){
            if(start>=rooms[i]){
                rooms[i] = end;
                tf = true;
                break;
            }
        }
        if(!tf){
            rooms.push_back(end);
        }
    }

    answer = rooms.size();
    return answer;
}