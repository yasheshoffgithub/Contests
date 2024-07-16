#include <bits/stdc++.h>
using namespace std;
// Contest Link:
// https://leetcode.com/contest/weekly-contest-401

// question 1
class Solution
{
public:
    int numberOfChild(int n, int k)
    {
        int position = 0;
        int direction = 1;

        for (int i = 0; i < k; ++i)
        {
            position += direction;

            // Reverse direction if the ball reaches either end
            if (position == n - 1)
            {
                direction = -1;
            }
            else if (position == 0)
            {
                direction = 1;
            }
        }

        return position;
    }
};

// question2
#define mod 1000000007
class Solution
{
public:
    int valueAfterKSeconds(int n, int k)
    {
        vector<int> pref(n, 1);
        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j < n; j++)
            {
                pref[j] = (pref[j] + pref[j - 1]) % mod;
            }
        }
        return pref[n - 1];
    }
};