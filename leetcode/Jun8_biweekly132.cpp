#include <bits/stdc++.h>
using namespace std;
// Contest Link:
// https://leetcode.com/contest/biweekly-contest-132
// question1
class Solution
{
public:
    string clearDigits(string s)
    {
        // basic approach to mark non digit elements to left to digit
        //  int n=s.length();
        //  for(int i=0;i<n;i++)
        //  {
        //      if(s[i]>=48 && s[i]<=57)
        //      {
        //          int j=i-1;
        //          while(j>=0 && !(s[j]>=97 && s[j]<=122))
        //          {
        //              j--;
        //          }
        //          if(j>=0) s[j]='/';
        //      }
        //  }
        //  string ans="";
        //  for(int i=0;i<n;i++)
        //  {
        //      if( (s[i]>=48 && s[i]<=57) || (s[i]=='/')) continue;
        //      else ans+=s[i];
        //  }
        //  return ans;

        // 2nd approach- to use a stack to store only non-digit elements and pop top element when a digit occurs
        stack<char> st;
        for (auto ch : s)
        {
            if (ch >= '0' && ch <= '9' && (!st.empty()))
            {
                st.pop();
            }
            else
                st.push(ch);
        }
        s = "";
        while (!st.empty())
        {
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

// question2
class Solution
{
public:
    int findWinningPlayer(vector<int> &s, int k)
    {
        int n = s.size();
        deque<int> pq;
        // Initialize the queue with players 1 to n-1
        for (int i = 1; i < n; i++)
        {
            pq.push_back(i);
        }
        int ele = 0, w = 0; // ele is the current winner, w is the win count
        while (w != k)
        {
            int num = pq.front();
            pq.pop_front();
            if (s[num] < s[ele])
            {
                w++;               // Current winner wins again
                pq.push_back(num); // Loser goes to end of queue
            }
            else
            {
                w = 1;             // New winner found
                pq.push_back(ele); // Previous winner goes to end of queue
                ele = num;         // Update current winner
            }
            if (w == k || w >= n - 1)
                return ele;
            // if same player wins n - 1 times then hes the winner
            // to avoid TLE ---> skills = [15,18] k = 386830937
        }
        return 1; // This line should never be reached
    }
};