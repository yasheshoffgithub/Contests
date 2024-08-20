#include <bits/stdc++.h>
using namespace std;

// contest link
// https://leetcode.com/contest/biweekly-contest-137/

//question 1
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n-k+1,-1);
        for(int i=0;i<n;i++){
            bool isCons=true;
            for(int j=i;j<i+k-1 && j<n-1;j++){
                if(nums[j+1]!=nums[j]+1){
                    isCons=false;
                    break;
                } 
            }
            if(i==n-k+1) return ans;
            if(isCons) ans[i]=nums[i+k-1];
        }
        return ans;
    }
};

//question 2

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - k + 1, -1);
        int score = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i && nums[i-1] + 1 == nums[i])
                score++;
            else
                score = 0;
            if (i >= k - 1 && score >= k - 1)
                ans[i - k + 1] = nums[i];
        }
        return ans;
    }
};