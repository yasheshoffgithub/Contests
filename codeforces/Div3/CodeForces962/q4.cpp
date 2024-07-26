#include <iostream>
#include <algorithm>

using namespace std;

int countTriplets(int n, int x) {
    long long count = 0; 

    for (int a = 1; a <= x; a++) {
        int max_b = min(n / a, x - a); 

        for (int b = 1; b <= max_b; b++) {
            int remaining_n = n - a * b; 
            int remaining_x = x - a - b; 

            if (remaining_n < 0 || remaining_x <= 0) {
                break;
            }

             
            int max_c = min(remaining_n / (a + b), remaining_x);
            count += max_c; 
        }
    }
    
    return count;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;
        cout << countTriplets(n, x) << endl;
    }

    return 0;
}
