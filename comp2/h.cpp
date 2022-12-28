#include <iostream>

#include <vector>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;

#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi>
#define ii pair<int, int>

#define bound 2000*100


void print_vec(vi v) {
    for (int i : v) {
        cout << i << ' ';
    }
    cout << endl;
}

void print_vec_bool(vb v) {
    for (int i : v) {
        cout << i << ' ';
    }
    cout << endl;
}

int len;
vi input;

// true if there's a subset that its sum is `sum`
bool isSumPossible(int sum) {
    if (sum > bound) return false;
    
    vector<vector<bool>> isPossible;
    isPossible.resize(input.size());
    for (int i = 0; i < input.size(); i++) {
        isPossible[i].resize(sum + 2);
    }

    isPossible[0][input[0]] = true;
    isPossible[0][0] = true;
    
    for (int i = 1; i < input.size(); ++i) {
        isPossible[i][0] = true;
        int x = input[i];
        for (int d = 0; d <= sum; d++) {
            if (isPossible[i-1][d]) {
                isPossible[i][d] = true;
            }
            if (d >= x && isPossible[i-1][d-x]) {
                isPossible[i][d] = true;
            }
        }
    }

    // print_vec(input);
    // cout << endl;
    // for (auto v : isPossible) {
    //     print_vec_bool(v);
    // }

    return isPossible[input.size() - 1][sum];
    
}


int getOddIndex() {
    for (int i = 0; i < len; ++i) {
        if (input[i] % 2 != 0) {
            return i;
        }
    }
    return -1;
}

int divideAllElementsBy2() {
    for (int i = 0; i < len; ++i) {
        input[i] /= 2;
        if (input[i] % 2 != 0) return i;
    }
    return -1;
}


void solve() {
    cin >> len;

    input.resize(len);

    int tmp;
    int sum = 0;
    for (int i = 0; i < len; ++i) {
        cin >> tmp;
        sum += tmp;
        input[i] = tmp;
    }

    if (sum % 2 != 0) {
        cout << 0 << endl;
        return;
    }

    if (isSumPossible(sum / 2)) {
        int index = getOddIndex();
        while (index == -1) {     
            index = divideAllElementsBy2();
        }
        cout << 1 << endl;
        cout << index + 1 << endl;
    } else {
        // 0
        cout << 0 << endl;
    }

    // sort(input.begin(), input.end());
    // for (int i = 0; i < len; ++i) {
    //     cout << input[i];
    // }



}


int main() {
    solve();
}