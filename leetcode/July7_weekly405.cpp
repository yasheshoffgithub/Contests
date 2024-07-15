#include <bits/stdc++.h>
using namespace std;

//question 1
// Problem Link 
// https://leetcode.com/problems/find-the-encrypted-string/description/
class Solution {
public:
    string getEncryptedString(string s, int k) {
        string ans="";
        int n=s.length();
        for(int i=0;i<n;i++){
            ans+=s[(i+k)%n];
        }
        return ans;
    }
};

//question 2
// Problem Link
// https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/description/

class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> result;
        string sb;
        generateStrings(result, sb, n, -1);
        return result;
    }

private:
    void generateStrings(vector<string>& result, string& sb, int n, int lastChar) {
        if (sb.length() == n) {
            result.push_back(sb);
            return;
        }

        // Add '1' to the string
        sb.push_back('1');
        generateStrings(result, sb, n, 1);
        sb.pop_back();

        // Add '0' to the string, only if the last character was not '0'
        if (lastChar != 0) {
            sb.push_back('0');
            generateStrings(result, sb, n, 0);
            sb.pop_back();
        }
    }
};