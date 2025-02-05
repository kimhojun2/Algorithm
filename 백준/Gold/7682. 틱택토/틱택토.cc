#include <iostream>
using namespace std;

char arr[3][3] = { 0, };

bool checkX() {
	//가로
	for (int i = 0;i < 3;i++) {
		if (arr[i][0] == 'X' && arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2]) return true;
	}
	//세로
	for (int i = 0;i < 3;i++) {
		if (arr[0][i] == 'X' && arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i]) return true;
	}
	//대각선
	if (arr[0][0] == 'X' && arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2]) return true;
	if (arr[0][2] == 'X' && arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0]) return true;
	
	return false;
}

bool checkO() {
	//가로
	for (int i = 0;i < 3;i++) {
		if (arr[i][0] == 'O' && arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2]) return true;
	}
	//세로
	for (int i = 0;i < 3;i++) {
		if (arr[0][i] == 'O' && arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i]) return true;
	}
	//대각선
	if (arr[0][0] == 'O' && arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2]) return true;
	if (arr[0][2] == 'O' && arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0]) return true;

	return false;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		string input;
		cin >> input;
		if (input == "end") break;
		
		int idx = 0;
		int O = 0;
		int X = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				arr[i][j] = input[idx++];
				if (arr[i][j] == 'O') {
					O++;
				}
				else if (arr[i][j] == 'X') {
					X++;
				}
			}
		}
		bool resultX = checkX();
		bool resultO = checkO();
		
		//X승리
		if (resultX && !resultO && X == O + 1) {
			cout << "valid" << '\n';
		}
		//O승리
		else if (!resultX && resultO && X == O) {
			cout << "valid" << '\n';
		}
		//무승부
		else if(!resultO && !resultX&& X==5 &&O==4){
			cout << "valid" << '\n';
		}
		else {
			cout << "invalid" << '\n';
		}


	}


	return 0;
}