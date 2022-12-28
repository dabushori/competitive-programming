#include <iostream>
#include <vector>

using namespace std;

vector<int> input;

// void add_suffix(int index, int num_to_add) {
//     for (int i = index; i < input.size(); ++i) { 
//         input[i] += num_to_add;
//     }
// }

void solve_case2(){
    int n; 
    cin >> n;
    input.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> input[i];
    }
 
    vector<vector<int>> histogram;
    histogram.resize(n + 1);
    for (int index = 1; index < n; index++) {
        int diff = input[index] - input[index + 1];
        if (diff > 0) {
            histogram[diff].push_back(index + 1);
        }
    }

    vector<int> indexes;
        
    int his_idx = 1;
    for (int op = 1; op <= n; ++op) {
        
        if (indexes.size() == 0) {
            while (his_idx < n && histogram[his_idx].size() == 0) {
                ++his_idx;
            }
        } else {
            his_idx = indexes.back();
            indexes.pop_back();
        }

        int couple_idx;
        if (histogram[his_idx].size() == 0) { 
            couple_idx = 1;
        } else {
            couple_idx = histogram[his_idx].back();
            histogram[his_idx].pop_back();
            if (his_idx > op) {
                indexes.push_back(his_idx);
                his_idx -= op;
                indexes.push_back(his_idx);
                histogram[his_idx].push_back(couple_idx);
            }
            
        }
        
        // add_suffix(couple_idx, op);
        cout << couple_idx << ' ';
    }

    // for (int index = 1; index <= n; index++) {
    //     cout << input[index] << ' ';
    // }
    
    cout << endl;
}



int main()
{
    int numTestCases; 
    cin >> numTestCases;
    
    for (int i = 0; i < numTestCases; i++) {
        solve_case2();            
    }
    
}


// void solve_case(){
//     int n; 
//     cin >> n;
//     input.resize(n);
//     for (int i = 0; i < n; i++) {
//         cin >> input[i];
//         // cout << input[i] << ' ';
//     }
//     // cout << endl;
    

//     int curr_idx = n - 1;
//     // int curr_idx = 0;

//     for (int op = 1; op <= n; ++op) {
//         while (curr_idx >= 1 && input[curr_idx] <= input[curr_idx + 1]) {
//             --curr_idx;
//         }
//         cout << curr_idx + 2 << ' ';
//         add_suffix(curr_idx + 1, op);
//     }
//     cout << endl;
    
//     for (int a : input) { 
//         cout << a << ' ';
//     }
//     cout << endl;
//     // cout << endl;
// }

