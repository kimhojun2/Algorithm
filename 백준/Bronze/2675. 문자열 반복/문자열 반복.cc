#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test_case;
    cin >> test_case;
    cin.ignore();

    int cnt = 0;
    while(cnt < test_case){
        string s;
        getline(cin, s);

        for(int i = 2; i < s.length(); i++){
            int mult = s[0] - '0';

            for(int j = 0; j < mult; j++){
                cout << s[i];
            }
        }
        cout << '\n';
        cnt ++;
    }
    return 0;
}