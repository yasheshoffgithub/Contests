#include <bits/stdc++.h>
using namespace std;

//question 1
// Problem Link 
// https://leetcode.com/problems/lexicographically-smallest-string-after-a-swap/description/
class Solution {
public:
    string getSmallestString(string s) {
        int maxi=INT_MIN;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]>s[i+1] && (s[i]-s[i+1])%2==0) {
                swap(s[i],s[i+1]);
                return s;
            }
        }
        return s;
    }
};

//question 2
// Problem Link
// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/


 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if (!head) return head;  // Handle edge case if the list is empty

        std::unordered_set<int> numSet(nums.begin(), nums.end());  // Use a set for fast lookup

        // Create a dummy node to handle deletions more gracefully, especially for head node
        ListNode dummy(0);
        dummy.next = head;
        ListNode* current = &dummy;

        while (current->next != NULL) {
            if (numSet.find(current->next->val) != numSet.end()) {
                // Skip the node to be deleted
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }

        return dummy.next;
    }
};

//question 3
// Problem Link
// https://leetcode.com/problems/minimum-cost-for-cutting-cake-i/description/

class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        // Sort the cuts in descending order
        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());

        int h = 1; // Number of horizontal segments
        int v = 1; // Number of vertical segments
        int i = 0; // Pointer for horizontal cuts
        int j = 0; // Pointer for vertical cuts
        int totalCost = 0;

        // While there are cuts left to process
        while (i < horizontalCut.size() && j < verticalCut.size()) {
            if (horizontalCut[i] >= verticalCut[j]) {
                totalCost += horizontalCut[i] * v;
                h++;
                i++;
            } else {
                totalCost += verticalCut[j] * h;
                v++;
                j++;
            }
        }

        // Process any remaining horizontal cuts
        while (i < horizontalCut.size()) {
            totalCost += horizontalCut[i] * v;
            h++;
            i++;
        }

        // Process any remaining vertical cuts
        while (j < verticalCut.size()) {
            totalCost += verticalCut[j] * h;
            v++;
            j++;
        }

        return totalCost;
    }
};

//question 4
//Problem Link
// https://leetcode.com/problems/minimum-cost-for-cutting-cake-ii/

class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        // Sort the cuts in descending order
        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());

        long long h = 1; // Number of horizontal segments
        long long v = 1; // Number of vertical segments
        int i = 0; // Pointer for horizontal cuts
        int j = 0; // Pointer for vertical cuts
        long long totalCost = 0; // Use long long to avoid overflow

        // While there are cuts left to process
        while (i < horizontalCut.size() && j < verticalCut.size()) {
            if (horizontalCut[i] >= verticalCut[j]) {
                totalCost += horizontalCut[i] * v;
                h++;
                i++;
            } else {
                totalCost += verticalCut[j] * h;
                v++;
                j++;
            }
        }

        // Process any remaining horizontal cuts
        while (i < horizontalCut.size()) {
            totalCost += horizontalCut[i] * v;
            h++;
            i++;
        }

        // Process any remaining vertical cuts
        while (j < verticalCut.size()) {
            totalCost += verticalCut[j] * h;
            v++;
            j++;
        }

        return totalCost ; // Return the result modulo 10^9 + 7
    }
};

