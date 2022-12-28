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


    int tmp;
    
    int result = 0;
    for (int i = 1; i <= numOfHeaps; ++i) {
        cin >> tmp;
        result ^= (tmp % 4);
    }

    if (result) {
        cout << "first" << endl;
    } else {   
        cout << "second" << endl;
    }
}


int main() {
    
    int numOfCases;
    cin >> numOfCases;
    for(int i = 0; i < numOfCases; ++i) {
        solve();
    }
}