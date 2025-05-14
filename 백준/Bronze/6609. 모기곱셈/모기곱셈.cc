#include <iostream>

using namespace std;

int main() {
    int m,p,l,e,r,s,n;
    while(cin>>m>>p>>l>>e>>r>>s>>n){
        for(int i=0;i<n;i++){
            int sum=m;
            m=p/s;
            p=l/r;
            l=sum*e;
        }
        cout<<m<<'\n';
    }
}