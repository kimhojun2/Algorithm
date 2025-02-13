#include <iostream>
using namespace std;

int gcd(long long a, long long b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {

	long long N, M;
	
	cin >> N >> M;
    int g;
    if (N == M) {
        g = N;
    }
    else if (N > M) {
        g = gcd(N, M);
    }
    else {
        g = gcd(M, N);
    }
    cout << N * M / g << '\n';


	return 0;
}