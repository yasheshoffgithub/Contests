#include <bits/stdc++.h>
using namespace std;
// Contest Link:
// https://leetcode.com/contest/weekly-contest-410/

//question1
class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int row=0,col=0;
        int i=0;
        while(i!=commands.size()){
            if(commands[i]=="LEFT") col--;
            else if(commands[i]=="RIGHT") col++;
            else if(commands[i]=="UP") row--;
            else row++;
            i++;
        }
        return row*n+col;
    }
};

//question2
class Solution {
public:
    vector<vector<int>> graph;
    int ans;
    int dfs(int node,int parent){
        int totalnodes=0;
        bool isGood=true;
        int subtreesize=-1;
        for(auto nbr:graph[node]){
            if(nbr==parent) continue;
            int currsize=dfs(nbr,node);
            if(subtreesize==-1) subtreesize=currsize;
            else if(currsize!=subtreesize) isGood=false;
            totalnodes+=currsize;
        }
        if(isGood) ans++;
        return totalnodes+1;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        graph.resize(n);
        for(auto it:edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        dfs(0,-1); // Node,Parent
        return ans;
    }
};

//question 3
class Solution {
public:
    int dp[2001][51][51];
long helper(int i, vector<int>& nums, int s, int e) {
    if (i == nums.size()) {
        return 1;
    }

    if(dp[i][s][e]!=-1){

       return dp[i][s][e];
    }
 
    long ans = 0;
    int j = s;
    int k = min(e, nums[i]);
    while (j <= 50 && k >= 0) {
        int sum = j + k;
        if (sum == nums[i]) {
            ans = (ans + helper(i + 1, nums, j, k)) % 1000000007;
            j++;
            k--;
        } else if (sum < nums[i]) {
            j++;
        } else {
            k--;
        }
    }


    dp[i][s][e]= ans;
    return ans;
}
int countOfPairs(vector<int>& nums) {

    for(int i=0; i<=nums.size(); i++){
        for(int j=0; j<=50; j++){
            for(int k=0; k<=50; k++){
                dp[i][j][k]=-1;
            }
        }
    }

    long ans = helper(0, nums, 0, 50);
    return (int) (ans);
}
};

//question 4
class Solution {
public:
    int MOD = 1e9 + 7;

    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1(n);
        vector<int> arr2(n);
        vector<vector<int>> dp(n, vector<int>(1001, 0));
        for (int j = 0; j <= nums[0]; j++)
            dp[0][j] = 1;
        for (int i = 1; i < n; i++){
            int ways = 0;
            int k = 0;
            for (int j = 0; j <= nums[i]; j++){
                // problem I
                // for (int j = 0; j <= nums[i]; j++){
                //     int ways = 0;
                //     for (int k = 0; k <= 50; k++){
                //         if (k <= j && nums[i - 1] - k >= nums[i] - j)
                //             ways = (ways + dp[i - 1][k]) % MOD;
                //     }
                //     dp[i][j] = ways;
                // }
                // problem II
                if (k <= min(j, j - (nums[i] - nums[i - 1]))){
                    ways = (ways + dp[i - 1][k]) % MOD;
                    k++;
                }
                dp[i][j] = ways;
            }
        }
        int res = 0;
        for (int i = 0; i <= 1000; i++)
            res = (res + dp[n - 1][i]) % MOD;
        return res;
    }
};