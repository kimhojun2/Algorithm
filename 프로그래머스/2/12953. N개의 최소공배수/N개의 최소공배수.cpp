#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int gcd(int A, int B) {
    while (B != 0) {
        int temp = A % B;
        A = B;
        B = temp;
    }
    return A;
}


int solution(vector<int> arr) {
    int answer = 0;
    queue<int>q;
    for(auto now : arr){
        q.push(now);
    }
    while(q.size()>1){
        int A = q.front();
        q.pop();
        int B = q.front();
        q.pop();
        int result = gcd(A,B);
        int new_value = (A / result) *B;
        q.push(new_value);
    }
    answer = q.front();
    return answer;
}