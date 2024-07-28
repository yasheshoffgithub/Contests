#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        string s;
        cin>>s;
        int cnt=s.length();
        if(cnt>10){
            s=s[0]+to_string(cnt-2)+s[cnt-1];
            cout<<s<<endl;
        } else cout<<s<<endl;
    }
    return 0;
}