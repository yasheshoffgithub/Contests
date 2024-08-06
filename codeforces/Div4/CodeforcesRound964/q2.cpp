#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        
        int suneet_wins = 0;
        
        // All possible combinations of flipping the cards
        int suneet_cards[2] = {a1, a2};
        int slavic_cards[2] = {b1, b2};
        
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                int suneet_round_wins = 0;
                int slavic_round_wins = 0;
                
                // Round 1
                if (suneet_cards[i] > slavic_cards[j]) {
                    ++suneet_round_wins;
                } else if (suneet_cards[i] < slavic_cards[j]) {
                    ++slavic_round_wins;
                }
                
                // Round 2
                if (suneet_cards[1 - i] > slavic_cards[1 - j]) {
                    ++suneet_round_wins;
                } else if (suneet_cards[1 - i] < slavic_cards[1 - j]) {
                    ++slavic_round_wins;
                }
                
                // Check if Suneet wins more rounds than Slavic
                if (suneet_round_wins > slavic_round_wins) {
                    ++suneet_wins;
                }
            }
        }
        
        cout << suneet_wins << endl;
    }
    
    return 0;
}
