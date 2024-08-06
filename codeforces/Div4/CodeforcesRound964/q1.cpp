#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        int digit1 = n / 10; // Get the tens digit
        int digit2 = n % 10; // Get the units digit
        
        int sum = digit1 + digit2;
        
        cout << sum << endl;
    }
    
    return 0;
}
