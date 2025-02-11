#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    int l = max(bill[0], bill[1]);
    int s = min(bill[0], bill[1]);
    int lw = max(wallet[0],wallet[1]);
    int sw = min(wallet[0],wallet[1]);
    while(l>lw || s>sw){
        if(l>lw || s>sw){
            int new_l = l/2;
            l = max(new_l, s);
            s = min(new_l,s);
            answer++;
        }
    }

    return answer;
}