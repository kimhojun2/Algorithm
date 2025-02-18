#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int i=1;i<=yellow;i++){
        if(yellow%i == 0){
            int j = yellow / i;
            cout << i<<j<<"\n";
            if(2*(i+j+4)-4 == brown){
                answer = {max(i,j)+2,min(i,j)+2};
            }
        }
    }
    return answer;
}