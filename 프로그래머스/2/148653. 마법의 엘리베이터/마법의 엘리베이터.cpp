#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int solution(int storey) {
    int answer = 0;
    while(storey>0){
        int rstorey = storey%10;
        
        if(rstorey > 5){
            answer += (10-rstorey);
            storey += (10-rstorey);
        }
        else if(rstorey<5){
            answer += rstorey;
            storey -= rstorey;
        }
        else{
            if ((storey / 10) % 10 >= 5) {
                storey += (10 - rstorey); 
            } else {
                storey -= rstorey;
            }
            answer += rstorey;
        }    
        storey /=10;
    }
    return answer;
}