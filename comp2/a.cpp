#include <iostream>

#include <vector>
#include <utility>

using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int, int>
#define loop(idx, lim, inc) for (int i = idx; i < lim; i += inc)

int n, k;
void solve() {
    vi moves; 
    
    vi states;
    states.resize(n + 1);
    for (int i = 0; i < k; i++) {
        int tmp;
        cin >> tmp;
        moves.push_back(tmp);
    }

    for (int i = 0; i < n; i++) {
        // if losing state.
        if (states[i] == 0) {
            for (int p : moves) {
                if (i + p <= n) {
                    states[i+p] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (states[i]) {
            cout << 'W';
        } else {
            cout << 'L';
        }
    }

    cout << endl;

}


int main() {
    cin >> n >> k;
    solve();
}