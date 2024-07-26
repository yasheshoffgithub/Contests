#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>> t;
    while(t--){
        int n;
        cin>> n;
        int cnt=0;
        while(n>2){
            n-=4;
            cnt++;
        } 
        if(n==0) cout<< cnt<<endl;
        else cout<< cnt+1<<endl;
    }
    return 0;
}