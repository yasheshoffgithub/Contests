#include <bits/stdc++.h>
using namespace std;
// Contest Link:
// https://leetcode.com/contest/biweekly-contest-133
// question 1
class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int minop = 0;
        for (auto i : nums)
        {
            if (i % 3 != 0)
                minop += 1;
        }
        return minop;
    }
};
// question2
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int ans = 0;
        int i = 0;
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i)
        {
            if (nums[i] == 0)
            {
                nums[i] = 1 - nums[i];
                nums[i + 1] = 1 - nums[i + 1];
                nums[i + 2] = 1 - nums[i + 2];
                ++ans;
            }
        }
        if (nums[n - 2] == 0 || nums[n - 1] == 0)
            return -1;
        return ans;
    }
};
// question3
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if ((nums[i] == 0 && ans % 2 == 0) || (nums[i] == 1 && ans % 2 != 0))
            {
                ans++;
            }
        }
        return ans;
    }
};