#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;cin>>t;
    while(t--){
        int n,x;
        string ans="NO";
        unordered_map<int,int> h;
        cin>>n;
        for(int i=0;i<n;i++) cin>>x,h[x]++;
        for(auto x:h) 
            if(x.second%2==1) 
                ans="YES";
        cout<<ans<<"\n";
    }
}