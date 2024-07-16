#include <bits/stdc++.h>
using namespace std;

// Contest Link:
// https://leetcode.com/contest/weekly-contest-403
// question1
class Solution
{
public:
    double minimumAverage(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<double> avg;
        int i = 0, k = 0, j = n - 1;
        while (k++ != (n / 2))
        {
            double a = (double)(nums[i++] + nums[j--]) / 2;
            avg.push_back(a);
        }
        sort(avg.begin(), avg.end());
        return avg[0];
    }
};

// question2
class Solution
{
public:
    int minimumArea(vector<vector<int>> &grid)
    {
        // basically we neeed min and max indices in both directions-vertical and horizontal
        // we can also do this by using 4 variables top,bottom,left,right
        vector<int> hor;
        vector<int> ver;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    hor.push_back(i);
                    ver.push_back(j);
                }
            }
        }
        sort(hor.begin(), hor.end());
        sort(ver.begin(), ver.end());
        return (hor.back() - hor[0] + 1) * (ver.back() - ver[0] + 1);
    }
};