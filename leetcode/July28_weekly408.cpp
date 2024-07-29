#include <bits/stdc++.h>
using namespace std;

//contest link
// https://leetcode.com/contest/weekly-contest-408/

//question1
class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum1=0,sum2=0;
        for(auto i:nums){
            if(i>9) sum2+=i;
            else sum1+=i;
        }
        return sum1!=sum2;
    }
};

//question 2

class Solution {
public:
    int nonSpecialCount(int l, int r) {
        //main idea behind it is that special number will be a perfect square of a prime no so we need to find primes in the range sqrt(l) to sqrt(r) and then check if their sqares lie in l to r.

        // Calculate the limit up to which we need to find prime numbers
        int lim = (int)(sqrt(r));

        // Create a boolean array to mark primes up to lim using Sieve of Eratosthenes
        vector<bool> v(lim + 1, true);
        v[0] = v[1] = false; // 0 and 1 are not prime numbers

        // Sieve of Eratosthenes to mark non-prime numbers
        for (int i = 2; i * i <= lim; i++) {
            if (v[i]) {
                for (int j = i * i; j <= lim; j += i) {
                    v[j] = false;
                }
            }
        }

        // Count special numbers in the range [l, r]
        int cnt = 0;
        for (int i = 2; i <= lim; i++) {
            if (v[i]) {
                int square = i * i;
                if (square >= l && square <= r) {
                    cnt++;
                }
            }
        }        
        return r - l + 1 - cnt;
    }
};

//question 4
class DisjointSet{
    vector<int> parent,size;
    public:
        DisjointSet(int n){
            size.resize(n+1,1);
            parent.resize(n+1,0);
            for(int i=0; i<=n; i++){
                parent[i]=i;
            }
        }
        int findUpar(int u){
            if(u==parent[u]){
                return u;
            }
            return parent[u]=findUpar(parent[u]);
        }
        void dsu(int u, int v){
            int ulpu=findUpar(u);
            int ulpv=findUpar(v);
            if(ulpv==ulpu){
                return;
            }
            if(size[ulpu]<size[ulpv]){
                parent[ulpu]=ulpv;
                size[ulpv]+=size[ulpu];
            }
            else{
                parent[ulpv]=ulpu;
                size[ulpu]+=size[ulpv];
            }
        }
};
class Solution {
public:
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        int n=circles.size();
        DisjointSet ds(n+5);
        int i=0;
        for(auto it:circles){
            int xi=it[0],yi=it[1],ri=it[2];
            if(xi<=ri){
                ds.dsu(i,n+3);
            }
            if(yi<=ri){
                ds.dsu(i,n);
            }
            if(X-xi<=ri){
                ds.dsu(i,n+1);
            }
            if(Y-yi<=ri){
                ds.dsu(i,n+2);
            }
            i++;
        }
        i=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int x1=circles[i][0];
                int y1=circles[i][1];
                int r1=circles[i][2];
                int x2=circles[j][0];
                int y2=circles[j][1];
                int r2=circles[j][2];
                double dist=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
                if(dist<=(r1+r2)){
                    ds.dsu(i,j);
                }
            }
        }
        if(ds.findUpar(n+3)==ds.findUpar(n+1)|| ds.findUpar(n+3)==ds.findUpar(n)){
            return false;
        }
        if(ds.findUpar(n+2)==ds.findUpar(n+1) || ds.findUpar(n+2)==ds.findUpar(n)){
            return false;
        }
        return true;
    }
};