#include <bits/stdc++.h>
using namespace std;

// contest link
// https://leetcode.com/contest/weekly-contest-411/

//question 1
class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int cnt=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            int zero=0;
            int ones=0;
            for(int j=i;j<n;j++){
                if(s[j]=='1') ones++;
                else zero++;
                if(zero<=k || ones<=k) cnt++;
            }
        }
        return cnt;
    }
};

//question 2
class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n=energyDrinkA.size();
        vector<long long> dpA(n,0);
        vector<long long> dpB(n,0);
        dpA[0]=energyDrinkA[0], dpB[0]=energyDrinkB[0];
        for(int i=1;i<n;i++){
            if(i==1){
                dpA[i]=max(dpA[i-1],(long long) 0)+energyDrinkA[i];
                dpB[i]=max(dpB[i-1],(long long) 0)+energyDrinkB[i];
            }
            else {
                dpA[i]=max(dpA[i-1],dpB[i-2])+energyDrinkA[i];
                dpB[i]=max(dpB[i-1],dpA[i-2])+energyDrinkB[i];
            }
        }
        return max(dpA[n-1],dpB[n-1]);
    }
};