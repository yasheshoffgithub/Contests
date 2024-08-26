#include <bits/stdc++.h>
using namespace std;

// contest link
// https://leetcode.com/contest/weekly-contest-412/

//question 1
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        while(k--){
            int val=pq.top().first;
            int ind=pq.top().second;
            pq.pop();
            pq.push({val*multiplier,ind});
            nums[ind]=val*multiplier;
        }
        return nums;
    }
};

//question 2
class Solution {
private:
    bool almostEqual(int x, int y){
        string s1 = to_string(x), s2 = to_string(y);
        int n = s1.length(), m = s2.length();
        int maxLen = max(n, m);
        // make the lengths of 2 strings equal by adding zeros to the front
        while(n != maxLen){
            s1 = "0" + s1; n++;
        }
        while(m != maxLen){
            s2 = "0" + s2; m++;
        }
        int diff = 0;
        unordered_map<char,int> mp1, mp2;
        for(int i = 0; i < n; i++){
            diff += (s1[i] != s2[i]);
            mp1[s1[i]]++; mp2[s2[i]]++;
        }
        //at max only two digits should be wrongly placed and freq map should be same of both strings
        return diff <= 2 && mp1 == mp2;
    }
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size(), count = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                count += almostEqual(nums[i], nums[j]);
            }
        }
        return count;
    }
};