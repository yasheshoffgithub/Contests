#include <bits/stdc++.h>
using namespace std;

//Contest Link
// https://leetcode.com/contest/biweekly-contest-135/

//question1
class Solution {
public:
    string losingPlayer(int x, int y) {
        int turn=0;
        while(x>0 && y>0){
            if(x-1<0 || y-4<0) break;
            x--;
            y-=4;
            turn=1-turn;
        }
        if(turn==0) return "Bob";
        return "Alice";
    }
};

//question2
class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> mp;
        for(char c:s) mp[c]++;
        int min_len=0;
        for(char c:s) {
            if(mp[c]>2){
                if(mp[c]%2==0) mp[c]=2;
                else mp[c]=1;
                min_len+=mp[c];
                mp.erase(c);
            }
            else{
                min_len+=mp[c];
                mp.erase(c);
            } 
        }
        return min_len;
    }
};