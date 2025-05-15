#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// 다시 풀어야함


int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1, max = 0;
    sort(mats.begin(), mats.end());
    for (int i = 0; i < park.size(); i++) {
        for (int j = 0; j < park[i].size(); j++) {
            if (park[i][j].compare("-1")) continue;
            int m = 1;
            while (i + m < park.size() && j + m < park[i].size())
            {
                int dx = 0, dy = 0;
                while (park[i + dy++][j+m].compare("-1") == 0 && dy <= m);
                while (park[i+m][j + dx++].compare("-1") == 0 && dx <= m);
                if (dy != dx || dy != m+1) break;
                
                m++;
            }
            max = max > m ? max : m;
        }
    }
    for (int i = mats.size() - 1; i >= 0; i--) {
        if (mats[i] <= max) return mats[i];
    }
    return answer;
}