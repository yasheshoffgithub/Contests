#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, s, m;
        cin >> n >> s >> m;
        
        vector<pair<int, int>> tasks(n);
        for (int i = 0; i < n; ++i) {
            cin >> tasks[i].first >> tasks[i].second;
        }

        bool canShower = false;

        if (tasks[0].first >= s) {
            canShower = true;
        }

        for (int i = 1; i < n && !canShower; ++i) {
            if (tasks[i].first - tasks[i-1].second >= s) {
                canShower = true;
            }
        }

        if (m - tasks[n-1].second >= s) {
            canShower = true;
        }

        if (canShower) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
