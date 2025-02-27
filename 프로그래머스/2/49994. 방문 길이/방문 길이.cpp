#include <string>
#include <iostream>
#include <set>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    set<pair<pair<int, int>, pair<int, int>>> visited;
    
    int y = 0, x = 0;
    
    for(char order : dirs){
        int ny = y, nx = x;

        if(order == 'L') nx--; 
        else if(order == 'R') nx++;
        else if(order == 'U') ny++;
        else if(order == 'D') ny--;

        if(ny < -5 || ny > 5 || nx < -5 || nx > 5) continue;


        pair<int, int> start = {y, x};
        pair<int, int> end = {ny, nx};

        if(visited.find({start, end}) == visited.end() && visited.find({end, start}) == visited.end()) {
            visited.insert({start, end});
            visited.insert({end, start});
            answer++;
        }

        y = ny;
        x = nx;
    }
    
    return answer;
}
