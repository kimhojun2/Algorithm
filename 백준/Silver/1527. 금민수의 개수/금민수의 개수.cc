#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int A, B;
long long result;

void goldMinWater(long long num) {
	if (num > B)
		return;

	if (A <= num && num <= B)
		result++;
	
	goldMinWater(num * 10 + 4);
	goldMinWater(num * 10 + 7);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> A >> B;

	goldMinWater(4);
	goldMinWater(7);

	cout << result;
}