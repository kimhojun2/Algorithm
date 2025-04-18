#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int T, x1, y1, r1, x2, y2, r2;
	cin >> T;

	while (T--)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double d = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));

		if (d == 0 && r1 == r2)
			cout << -1;

		else if (d > r1 + r2 || d < abs(r1 - r2))
			cout << 0;

		else if (d == r1 + r2 || d == abs(r1 - r2))
			cout << 1;

		else if (d < r1 + r2)
			cout << 2;

		cout << "\n";
	}
}