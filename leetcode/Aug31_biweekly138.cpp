#include <bits/stdc++.h>
using namespace std;

// contest link
// https://leetcode.com/contest/biweekly-contest-138/

//question 1
class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string s1=to_string(num1);
        string s2=to_string(num2);
        string s3=to_string(num3);
        while(s1.length()!=4) s1="0"+s1;
        while(s2.length()!=4) s2="0"+s2;
        while(s3.length()!=4) s3="0"+s3;
        string key="";
        for(int i=0;i<4;i++) key+=min(s1[i],min(s2[i],s3[i]));
        return stoi(key);
    }
};

//question 2
class Solution {
public:
    string stringHash(string s, int k) {
        int n=s.length();
        string result="";
        for(int i=0;i<n;i+=k){
            int sum=0;
            for(int j=i;j<i+k &&j<n;j++){
                sum+=s[j]-'a';
            }
            result+=('a'+sum%26);
        }
        return result;
    }
};