#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int>m = {
        {'R',0},
        {'T',0},
        {'C',0},
        {'F',0},
        {'J',0},
        {'M',0},
        {'A',0},
        {'N',0}
    };
    for(int i=0;i<survey.size();i++){
        char front = survey[i][0];
        char back = survey[i][1];
        if(choices[i]<4){
            m[front] += (4-choices[i]);
        }
        else if(choices[i] > 4){
            m[back] += (choices[i]-4);
        }
    }
    if(m['R'] >= m['T']) answer+='R';
    else answer +='T';
    if(m['C'] >= m['F']) answer+='C';
    else answer +='F';
    if(m['J'] >= m['M']) answer+='J';
    else answer +='M';
    if(m['A'] >= m['N']) answer+='A';
    else answer +='N';
    
    return answer;
}