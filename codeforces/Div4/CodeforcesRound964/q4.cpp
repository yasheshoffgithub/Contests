#include <iostream>
#include <string>

using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;

    int tIndex = 0; // Pointer for t
    int sIndex = 0; // Pointer for s

    // Iterate until either t or s is exhausted
    while (sIndex < s.size() && tIndex < t.size()) {
        if (s[sIndex] == t[tIndex]) {
            // Characters match, move to next in both strings
            sIndex++;
            tIndex++;
        } else if (s[sIndex] == '?') {
            // Replace wildcard with the character from t
            s[sIndex] = t[tIndex];
            sIndex++;
            tIndex++;
        } else {
            // Mismatch and not a wildcard, move to next in s
            sIndex++;
        }
    }

    // If any characters of t are remaining, it's not a subsequence
    if (tIndex != t.size()) {
        cout << "NO\n";
        return;
    }

    // Replace any remaining wildcards with 'a'
    while (sIndex < s.size()) {
        if (s[sIndex] == '?') {
            s[sIndex] = 'a';
        }
        sIndex++;
    }

    cout << "YES\n" << s << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
