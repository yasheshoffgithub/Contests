#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> scores;
    for(int i=0;i<n;i++){
        int val; cin>>val;
        scores.push_back(val);
    }
    sort(scores.rbegin(),scores.rend());
    int x=scores[k-1];
    int cnt=0;
    for(auto it:scores) cnt+=(it>=x && it>0);
    cout<<cnt;
}