#include <bits/stdc++.h>
using namespace std;

//question 1
// Problem Link 
// https://leetcode.com/problems/alternating-groups-i/description/
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int alt=0;
        int n=colors.size();
        for(int i=1;i<n-1;i++){
            if(colors[i]!=colors[i-1] && colors[i]!=colors[i+1]) alt++;
        }
        if(colors[0]!=colors[n-1] && colors[0]!=colors[1]) alt++;
        if(colors[n-2]!=colors[n-1] && colors[n-1]!=colors[0]) alt++;
        return alt;
    }
};

//question 2
// Problem Link 
// https://leetcode.com/problems/maximum-points-after-enemy-battles/description/
class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        long long maxpoints = 0;
        int n = enemyEnergies.size();
        int j = n - 1;
        sort(enemyEnergies.begin(), enemyEnergies.end());
        if(enemyEnergies[0] > currentEnergy) return 0;
        while(j >= 0){
            if(enemyEnergies[0] <= currentEnergy){
                maxpoints += currentEnergy/enemyEnergies[0];
                currentEnergy %= enemyEnergies[0];
            }
            else{
                currentEnergy += enemyEnergies[j];
                j--;
            }
        }
        return maxpoints;
    }
};

//question 3
// Problem Link 
// https://leetcode.com/problems/alternating-groups-ii/description/
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& c, int k) {
    int l = 1, r = 0, a = c[c.size() - 1]; 
    for(int i = 1; i < c.size(); ++i) // Traverse the array from the second tile.
        if(c[i] != c[i - 1] and ++l >= k) ++r; // If current tile is different from previous and length reaches k, increment r.
        else if (c[i] == c[i - 1]) l = 1; // If current tile is same as previous, reset length to 1.
    for(int i = 0 ; i < k - 1; ++i) // Traverse the first k-1 tiles to handle circular nature.
        if(c[i] != a){ if(++l >= k) ++r; a = c[i]; } // If current tile is different from last, check length and increment r if needed.
        else l = 1; // If current tile is same as last, reset length to 1.
    return r; // Return the count of alternating groups.
}
};

//question 4
// Problem Link 
// https://leetcode.com/problems/number-of-subarrays-with-and-value-of-k/description/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> andMap;  // Stores current AND results and their counts
    long long count = 0;

    for (int i = 0; i < n; ++i) {
        unordered_map<int, int> newAndMap;
        
        // Each element itself is a subarray
        newAndMap[nums[i]]++;

        // Update new AND results with the current element
        for (auto& [andResult, cnt] : andMap) {
            int newAndResult = andResult & nums[i];
            newAndMap[newAndResult] += cnt;
        }

        // Update the main map
        andMap = newAndMap;

        // Check if any of the current AND results equal k
        if (andMap.find(k) != andMap.end()) {
            count += andMap[k];
        }
    }

    return count;
    }
};