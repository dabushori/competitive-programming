#include <iostream>
#include <bits/stdc++.h>
#include <stdint.h>

#include <vector>
#define int int64_t
#define vi vector<int64_t>


using namespace std;

void solve() {
    int n;
    cin >> n;
    vi distances;
    distances.resize(n);
    cin >> distances[0];

    int sum = 0;
    for (int i = 1; i < n; i++) {
        int tmp;
        cin >> tmp;
        distances[i] = tmp;
        
        sum += tmp;
    }
    // cout << endl;

    sort(distances.begin(), distances.end());

    int result = distances[n-1];
    for (int index = 1; index < n; index++) {
        // cout << sum << endl;
        result -= sum;
        int diff = distances[index] - distances[index-1];
        // cout << diff << endl;
        sum -= (diff) * (n - index);
        // cout << sum << endl;
 
    }

    cout << result << endl;
    // cout << endl;

}


int32_t main() {
    int numOfTests;
    cin >> numOfTests;

    for (int i = 0; i < numOfTests; i++) { 
        solve();
    }
}