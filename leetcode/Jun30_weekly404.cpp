#include <bits/stdc++.h>
using namespace std;

// question1
class Solution
{
public:
    int maxHeightOfTriangle(int red, int blue)
    {
        int maxr = 0;
        int maxb = 0;
        int rb = red;
        int bb = blue;
        // check for red as top
        for (int i = 1;; i++)
        {
            // odd level should be red
            if (i % 2 == 1)
            {
                if (rb - i >= 0)
                    rb -= i;
                else
                    break;
            }
            else
            {
                if (bb - i >= 0)
                    bb -= i;
                else
                    break;
            }
            maxr++;
        }
        rb = red;
        bb = blue;
        // check for blue as start
        for (int i = 1;; i++)
        {
            // even level should be red
            if (i % 2 == 0)
            {
                if (rb - i >= 0)
                    rb -= i;
                else
                    break;
            }
            else
            {
                if (bb - i >= 0)
                    bb -= i;
                else
                    break;
            }
            maxb++;
        }
        return max(maxr, maxb);
    }
};

// question2
class Solution
{
public:
    int sameParity(vector<int> &nums)
    {
        int n = nums.size();

        // longest subsequence if previous and current term are even
        vector<int> even(n, 0);
        if (nums[0] % 2 == 0)
            even[0] = 1;

        for (int i = 1; i < n; i++)
        {
            int val = nums[i];

            if (val % 2 == 1)
            {
                even[i] = even[i - 1];
            }
            else
            {
                even[i] = even[i - 1] + 1;
            }
        }

        // longest subsequence if previous and current term are odd
        vector<int> odd(n, 0);
        if (nums[0] % 2 == 1)
            odd[0] = 1;

        for (int i = 1; i < n; i++)
        {
            int val = nums[i];
            if (val % 2 == 0)
            {
                odd[i] = odd[i - 1];
            }
            else
            {
                odd[i] = odd[i - 1] + 1;
            }
        }

        return max(even[n - 1], odd[n - 1]);
    }

    int alternatingParity(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> even(n, 0); // longest subsequence if previous is odd and current is even
        vector<int> odd(n, 0);  // longest subsequence if previous is even and current is odd

        if (nums[0] % 2 == 0)
            even[0] = 1;
        if (nums[0] % 2 == 1)
            odd[0] = 1;

        for (int i = 1; i < n; i++)
        {
            int val = nums[i];

            if (val % 2 == 0)
            {
                even[i] = 1 + odd[i - 1];
                odd[i] = odd[i - 1];
            }
            else
            {
                odd[i] = 1 + even[i - 1];
                even[i] = even[i - 1];
            }
        }

        return max(even[n - 1], odd[n - 1]);
    }

    int maximumLength(vector<int> &nums)
    {
        // there are 4 possible cases
        return max(sameParity(nums), alternatingParity(nums));
    }
};