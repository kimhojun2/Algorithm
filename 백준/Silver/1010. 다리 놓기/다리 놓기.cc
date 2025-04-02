#include <iostream>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);   cin.tie(nullptr);

    int T, N, M, tmp, result;

    cin >> T;

    while (T--) 
    {
        result = 1;
        tmp = 1;
        cin >> M >> N;

        for (int i = N; i > N - M; --i) 
        {
            result *= i;
            result /= tmp++;
        }

        cout << result << "\n";
    }
}