#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<string> grid(n); 
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    int new_size = n / k; 
    vector<string> reducedGrid(new_size, string(new_size, '0'));

    for (int row = 0; row < new_size; ++row) {
        for (int col = 0; col < new_size; ++col) {
            reducedGrid[row][col] = grid[row * k][col * k]; 
        }
    }

    for (const string& row : reducedGrid) {
        cout << row << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
