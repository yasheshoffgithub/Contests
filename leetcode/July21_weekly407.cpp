#include <bits/stdc++.h>
using namespace std;

// Contest link
// https://leetcode.com/contest/weekly-contest-407/

//question 1
class Solution {
public:
    int minChanges(int n, int k) {
    if((n&k) !=k) return -1;
    int count = 0;
    for (int i = 0; i < 32; i++) {
        if (((n >> i) & 1)== 1 && ((k >> i) & 1)==0) {
            count++;
        }
      }
      return count;
    }
};

//question 2
class Solution {
public:
    bool doesAliceWin(string s) {
        int vowels=0;
        for(char c:s){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') vowels++;
        }
        if(vowels==0) return false;
        return true;
    }
};

//question 3
class Solution {
public:
    int maxOperations(string s) {
        int n=s.length();
        int changes=0;
        int ones=0;
        bool flag=false;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                flag=false;
                ones++;
            } 
            if(s[i]=='0' && flag==false ){
                changes+=ones;
                flag=true;
            } 
        }
        return changes;
    }
};