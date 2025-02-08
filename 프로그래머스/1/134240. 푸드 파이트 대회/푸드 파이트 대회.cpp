#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    for(int i=1;i<food.size();i++){
        if(food[i]>1){
            while(food[i]-2>=0){
                answer += to_string(i)[0];
                food[i] -= 2;
            }
        }
    }
    answer = answer + '0' + string(answer.rbegin(), answer.rend());
    return answer;
}