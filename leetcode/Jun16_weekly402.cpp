#include <bits/stdc++.h>
using namespace std;

// Contest Link:
// https://leetcode.com/contest/weekly-contest-402

// solution1
class Solution
{
public:
    int countCompleteDayPairs(vector<int> &hours)
    {
        int n = hours.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((hours[i] + hours[j]) % 24 == 0)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
// solution2
class Solution
{
public:
    long long countCompleteDayPairs(vector<int> &hours)
    {
        int n = hours.size();
        long long cnt = 0;
        unordered_map<int, long long> mp;
        for (int i = 0; i < n; i++)
        {
            cnt += mp[(24 - hours[i] % 24) % 24];
            mp[hours[i] % 24]++;
        }
        return cnt;
    }
};