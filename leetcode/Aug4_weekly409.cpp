#include <bits/stdc++.h>
using namespace std;

// contest link
// https://leetcode.com/contest/weekly-contest-409/

//question 1
class neighborSum {
public:
    neighborSum(vector<vector<int>>& grid) : grid(grid), n(grid.size()) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                valueToCoordinates[grid[i][j]] = {i, j};
            }
        }
    }
    
    int adjacentSum(int value) {
        if (valueToCoordinates.find(value) == valueToCoordinates.end()) {
            return 0;
        }
        
        int i = valueToCoordinates[value].first;
        int j = valueToCoordinates[value].second;
        
        int sum = 0;
        
        if (i > 0) sum += grid[i - 1][j];
        
        if (i < n - 1) sum += grid[i + 1][j];
        
        if (j > 0) sum += grid[i][j - 1];
        
        if (j < n - 1) sum += grid[i][j + 1];
        
        return sum;
    }
    
    int diagonalSum(int value) {
        if (valueToCoordinates.find(value) == valueToCoordinates.end()) {
            return 0;
        }
        
        int i = valueToCoordinates[value].first;
        int j = valueToCoordinates[value].second;
        
        int sum = 0;
        
        if (i > 0 && j > 0) sum += grid[i - 1][j - 1];
        
        if (i > 0 && j < n - 1) sum += grid[i - 1][j + 1];
        
        if (i < n - 1 && j > 0) sum += grid[i + 1][j - 1];
        
        if (i < n - 1 && j < n - 1) sum += grid[i + 1][j + 1];
        
        return sum;
    }

private:
    vector<vector<int>> grid;
    int n;
    unordered_map<int, pair<int, int>> valueToCoordinates;
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */

// question 2
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        
        vector<vector<int>> graph(n);
        for (int i = 0; i < n - 1; ++i) {
            graph[i].push_back(i + 1);
        }
        
        vector<int> answer;
        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];
            graph[u].push_back(v);

            
            vector<int> dist(n, INT_MAX);
            queue<int> q;
            dist[0] = 0;
            q.push(0);
            
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (int neighbor : graph[curr]) {
                    if (dist[curr] + 1 < dist[neighbor]) {
                        dist[neighbor] = dist[curr] + 1;
                        q.push(neighbor);
                    }
                }
            }
            
            answer.push_back(dist[n - 1] == INT_MAX ? -1 : dist[n - 1]);
        }
        
        return answer;
    }
};

//question 3
class Solution {
public:
    void sol(set<int>& s, int l, int r) {
        auto it_start = s.lower_bound(l);
        auto it_end = s.upper_bound(r);
        s.erase(it_start, it_end);
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
    //middle nodes won't contribute to the shortest path so we can remove them
    //and min distance will be no of nodes-1 (remaining-1)
        set<int>s;    
        for(int i=0;i<n;i++) s.insert(i);
        vector<int>ans;
        for(auto &i:queries){
            int x=i[0],y=i[1];
            sol(s,x+1,y-1);  //Nodes to be erased will l+1 to r-1 (Not l to r)
            ans.push_back(s.size()-1);
        }
        return ans;
    }
};