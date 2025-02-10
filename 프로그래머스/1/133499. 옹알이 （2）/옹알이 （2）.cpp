#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    int idx = 0;
    int last = -1;
    for(auto now : babbling){
        bool tf = true;
        while(idx<now.size()){
            if(now.substr(idx,3)=="aya"&&last!=1){
                idx +=3;
                last = 1;
            }
            else if(now.substr(idx,2) == "ye"&&last!=2){
                idx +=2;
                last = 2;
            }
            else if(now.substr(idx,3) =="woo"&&last!=3){
                idx +=3;
                last =3;
            }
            else if(now.substr(idx,2) =="ma"&&last!=4){
                idx +=2;
                last = 4;
            }
            else{
                tf = false;
                break;
            }
        }
        idx =0;
        last = -1;
        if(tf){
            answer++;
        }
    }
    return answer;
}