#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    int ig = 0;
    int i1 = 0;
    int i2 = 0;
    while (ig < goal.size()) {
        if (i1 < cards1.size() && goal[ig] == cards1[i1]) {
            i1++;
        } 
        else if (i2 < cards2.size() && goal[ig] == cards2[i2]) {
            i2++;
        } 
        else {
            answer = "No";
            break;
        }
        ig++;
    }
    return answer;
}