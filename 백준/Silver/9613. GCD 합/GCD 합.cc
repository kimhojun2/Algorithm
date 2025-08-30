#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    
    int t, n;
    long long count = 0;
    cin >> t;
    
    int arr[100];
    
    for(int i=0;i<t;i++) {
        count = 0;
        cin >> n;
        
        for(int j=0;j<n;j++) {
            cin >> arr[j];
        }
        
        for(int k=0;k<n-1;k++) {
            for(int q = k+1;q<n;q++) {
                count += gcd(arr[k], arr[q]);
            }
        }
        cout << count << endl;
    }
    
    return 0;
}