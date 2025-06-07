#include <iostream>
#include <queue>
#define endl '\n'
#define MAX 1000005
using namespace std;
int F, S, G, U, D;
int dist[MAX];
 
bool inRange(int x)
{
    return x >= 1 && x <= F;
}
void BFS(queue<int>& q)
{
    while (q.size())
    {
        int pos = q.front();
        q.pop();
 
        int nextU = pos + U;
        if (inRange(nextU) && !dist[nextU])
        {
            dist[nextU] = dist[pos] + 1;
            q.push(nextU);
        }
 
        int nextD = pos - D;
        if (inRange(nextD) && !dist[nextD])
        {
            dist[nextD] = dist[pos] + 1;
            q.push(nextD);
        }
    }
    if (dist[G])
        cout << dist[G] - 1 << endl;
    else
        cout << "use the stairs" << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    cin >> F >> S >> G >> U >> D;
    queue<int> Q;
    Q.push(S);
    dist[S] = 1;
    BFS(Q);
    return 0;
}
