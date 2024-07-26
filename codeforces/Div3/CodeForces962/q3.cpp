#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string a, b;
        cin >> a >> b;

        
        vector<vector<int>> pref_a(n + 1, vector<int>(26, 0)); 
        vector<vector<int>> pref_b(n + 1, vector<int>(26, 0));

        
        for (int i = 0; i < n; ++i) {
            for (int c = 0; c < 26; ++c) {
                pref_a[i + 1][c] = pref_a[i][c] + (a[i] - 'a' == c);
                pref_b[i + 1][c] = pref_b[i][c] + (b[i] - 'a' == c);
            }
        }

        
        while (q--) {
            int l, r;
            cin >> l >> r;

            int operations = 0;
            for (int c = 0; c < 26; ++c) {
                operations += abs(pref_a[r][c] - pref_a[l - 1][c] - (pref_b[r][c] - pref_b[l - 1][c]));
            }

            cout << operations / 2 << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
