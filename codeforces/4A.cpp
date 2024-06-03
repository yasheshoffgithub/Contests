#include <bits/stdc++.h>
using namespace std;
int main()
{
    int w;
    cin >> w;
    bool ans;
    ans = !(w & 1);
    if (ans & w > 2)
        cout << "YES";
    else
        cout << "NO";
    // return 0;
}
