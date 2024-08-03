#include <bits/stdc++.h>
using namespace std;

// contest link
// https://leetcode.com/contest/biweekly-contest-136/

//question 1
class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
    vector<int> wins(n, 0); 
    vector<unordered_map<int, int>> colorCount(n);
    for (const auto& p : pick) {
        int player = p[0];
        int color = p[1];
        colorCount[player][color]++;
    }
    for (int i = 0; i < n; ++i) {
        for (const auto& entry : colorCount[i]) {
            if (entry.second > i) {
                wins[i] = 1;
                break;
            }
        }
    }
    int result = 0;
    for (const auto& win : wins) {
        result += win;
    }
    return result;
    }
};

//question 2
class Solution {
public:
int countFlips(vector<int>& line) {
    int flips = 0;
    int n = line.size();
    for (int i = 0; i < n / 2; ++i) {
        if (line[i] != line[n - i - 1]) {
            flips++;
        }
    }
    return flips;
}

int minFlips(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    
    // Calculate flips required for rows
    int rowFlips = 0;
    for (int i = 0; i < m; ++i) {
        rowFlips += countFlips(grid[i]);
    }
    
    // Calculate flips required for columns
    int colFlips = 0;
    for (int j = 0; j < n; ++j) {
        vector<int> col(m);
        for (int i = 0; i < m; ++i) {
            col[i] = grid[i][j];
        }
        colFlips += countFlips(col);
    }
    
    // Return the minimum of rowFlips and colFlips
    return min(rowFlips, colFlips);
}
};