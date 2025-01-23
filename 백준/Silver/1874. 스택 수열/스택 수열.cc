#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(void)
{
	vector<char>output;
	stack<int>seq;
	int n;
	int cnt = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		while (cnt <= num)
		{
			seq.push(cnt);
			cnt++;
			output.push_back('+');
		}
		if (seq.top() == num)
		{
			seq.pop();
			output.push_back('-');
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}
	for (int i = 0; i < output.size(); i++)
		cout << output[i] << '\n';
}