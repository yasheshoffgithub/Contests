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