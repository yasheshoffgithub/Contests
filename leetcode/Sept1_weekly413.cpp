#include <bits/stdc++.h>
using namespace std;

// contest link
// https://leetcode.com/contest/weekly-contest-413/

//question 1
class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int sum1=coordinate1[0]-'a'+coordinate1[1]-'0';
        int sum2=coordinate2[0]-'a'+coordinate2[1]-'0';
        return sum1%2==sum2%2;
    }
};

//question 2
class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> pq;
        vector<int> result;
        int n=queries.size();
        for(int i=0;i<n;i++){
            int dist=abs(queries[i][0])+abs(queries[i][1]);
            if(pq.size()<k){
                pq.push(dist);
            } 
            else if(pq.top()>dist){
                pq.pop();
                pq.push(dist);
            }
            if(pq.size()<k) result.push_back(-1);
            else result.push_back(pq.top());
        }
        return result;
    }
};