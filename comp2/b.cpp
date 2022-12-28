#include <iostream>

#include <vector>
#include <utility>

using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int, int>




void solve() {
    int numOfHeaps;
    cin >> numOfHeaps;
    int res = 0;
    for (int i = 0; i < numOfHeaps; ++i) {
        int tmp;
        cin >> tmp;
        res ^= tmp;
    }

    if (res == 0) {
        cout << "second" << endl;
    } else {
        cout << "first" << endl;
    }
}


int main() {
    int numOfCases;
    cin >> numOfCases;
    for(int i = 0; i < numOfCases; ++i) {
        solve();
        
    }
}