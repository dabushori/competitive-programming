#include <iostream>

#include <vector>
#include <utility>

using namespace std;

#define vb vector<bool>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int, int>

#define max_n 2000

vi states;

int max_zero = 0;
void preprocessing() {
    states.resize(max_n+1);
    states[1] = 0;
    states[2] = 0;
    

    for (int i = 1; i <= max_n; ++i) {
        vb seen;
        seen.resize(i / 2 + 2);
        for (int j = 1; j < (i / 2) + (i % 2); ++j) {
            int tmp = states[j] ^ states[i - j];
            seen[tmp] = true;
            
        }
        for (int idx = 0; idx < i / 2 + 2; ++idx) {
            if (!seen[idx]) {
                states[i] = idx;
                break;
            }
        }
        if (states[i] == 0) {
            max_zero = i;
        }
    }
}


void solve() {
    int numOfCoins;
    cin >> numOfCoins;

    if (numOfCoins > max_n) {
        cout << "first" << endl;
        return;
    }

    if (states[numOfCoins]) {
        cout << "first" << endl;
    } else {   
        cout << "second" << endl;
    }
}

int main() {
    preprocessing();
    

    int numOfCases;
    cin >> numOfCases;
    for(int i = 0; i < numOfCases; ++i) {
        solve();
    }
}