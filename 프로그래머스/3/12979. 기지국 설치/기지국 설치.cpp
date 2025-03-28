#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int range = 2 * w + 1;
    int start = 1;

    for (int station : stations) {
        int left = station - w;
        int right = station + w;
        
        if (start < left) {
            int len = left - start;
            answer += (len + range - 1) / range;
        }

        start = right + 1;
    }

    if (start <= n) {
        int len = n - start + 1;
        answer += (len + range - 1) / range;
    }

    return answer;
}
