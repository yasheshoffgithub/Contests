#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int cnt=0;
    for(int i=0;i<n;i++){
        int p,v,t;
        cin>>p>>v>>t;
        if(p+v+t>1) cnt++;
    }
    cout<<cnt;
}