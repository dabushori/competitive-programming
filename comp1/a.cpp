#include <iostream>
#include <vector>
#include <map>

using namespace std;


void solve_case(){
    int n; 
    cin >> n;
    vector<int> input;
    input.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    // divide until between 1 and n
    for (int i = 0; i < n; i++) {
        while (input[i] > n) {
            input[i] /= 2;
        }
    }
    
    // create histogram map
    vector<int> histogram;
    histogram.resize(n+1);
    for (int i : input) {
        histogram[i] += 1;
    }

    // iterate from n to 1 and divide duplicates
    for (int i = n; i > 0; --i) {
        int curr_size = histogram[i];
        if (curr_size == 0) {
            // NO
            cout << "NO" << endl;
            return;
        } else if (curr_size > 1) {
            int tmp = curr_size - 1;
            histogram[i] = 1;
            histogram[i / 2] += tmp;
        }
    }
    if (histogram[0] > 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}



int main()
{
    int numTestCases; 
    cin >> numTestCases;
    
    for (int i = 0; i < numTestCases; i++) {
        solve_case();            
    }
}