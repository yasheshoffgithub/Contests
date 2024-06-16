#include <bits/stdc++.h>
using namespace std;

// question 1
class Solution
{
public:
    int minimumChairs(string s)
    {
        int cnt = 0, ans = 0;
        for (char c : s)
        {
            if (c == 'E')
                cnt++;
            if (c == 'L')
                cnt--;
            ans = max(ans, cnt);
        }
        return ans;
    }
};

// question 2
class Solution
{
public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        sort(meetings.begin(), meetings.end());
        int ans = meetings[0][0] - 1;
        int n = meetings.size();
        int last = meetings[0][1];
        for (int i = 1; i < n; i++)
        {
            if (meetings[i][0] > last)
                ans += (meetings[i][0] - last - 1); // count free days-only possible when gap exists
            last = max(last, meetings[i][1]);       // update last to keep checking
        }
        ans += (days - last);
        return ans;
    }
};
