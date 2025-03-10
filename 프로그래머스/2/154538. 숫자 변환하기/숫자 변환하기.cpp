#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int x, int y, int n) {
    queue<int> q;
    vector<int> visited(y + 1, 0);  
    q.push(x);
    visited[x] = 1;
    if(x==y){
        return 0;
    }
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < 3; i++) {
            int next;
            switch (i) {
                case 0:
                    next = now + n;
                    break;
                case 1:
                    next = now * 2;  
                    break;
                case 2:
                    next = now * 3; 
                    break;
            }

            if (next <= y && visited[next] == 0) {
                visited[next] = visited[now] + 1; 
                if (next == y) {
                    return visited[next] - 1; 
                }
                q.push(next);
            }
        }
    }

    return -1;
}
