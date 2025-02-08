#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 100001;

int main() {
    ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	
	int a,b,c;
	string ans;
	while(cin >> a >> b >> c) {
	    if(a==0 && b==0 && c==0) {
	        break;
	    }
	    
	    if(!((a<b+c) && (b<a+c) && (c<a+b))) {
	        ans = "Invalid";
	    } else if(a==b && b==c) {
	        ans = "Equilateral";
	    } else if(a==b || b==c || a==c) {
	        ans = "Isosceles";
	    } else {
	        ans = "Scalene";
	    }
	    
	    cout << ans << "\n";
	}

    return 0;
}