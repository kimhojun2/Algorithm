#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int check[24] = {0,};
    for(int i=0;i<24;i++){
        int player = players[i];
        if(player>=(check[i]+1)*m){
            int add = (player/m) - check[i];
            answer += add;
            for(int j =i;j<i+k;j++){
                if(j>=24) break;
                check[j]+=add;
            }
        }
    }
    return answer;
}