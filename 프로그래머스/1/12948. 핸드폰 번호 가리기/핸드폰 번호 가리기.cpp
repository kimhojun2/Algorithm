#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int L = phone_number.size()-4;
    for(int i=0;i<L;i++){
        phone_number[i] = '*';
    }
    return phone_number;
}