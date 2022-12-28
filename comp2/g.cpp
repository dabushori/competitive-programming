    #include <iostream>

    #include <vector>
    #include <utility>
    #include <algorithm>

    using namespace std;

    #define vi vector<int>
    #define vvi vector<vi>
    #define ii pair<int, int>


    vi input;

    void solve() {
        int m;
        cin >> m;
        vi r1;
        vi r2;
        r1.resize(m);
        r2.resize(m);

        for (int i = 0; i < m; i++) {
            cin >> r1[i];
        }

        for (int i = 0; i < m; i++) {
            cin >> r2[i];
        }

        vi r1_sub_sum_prefix;
        int previous = 0;
        for (int x : r1) {
            previous += x;
            r1_sub_sum_prefix.push_back(previous);
        }


        vi r2_sub_sum_prefix;
        previous = 0;
        for (int x : r2) {
            previous += x;
            r2_sub_sum_prefix.push_back(previous);
        }

        int row1_sum = r1_sub_sum_prefix[m-1];
        int row2_sum = r2_sub_sum_prefix[m-1];
        int minmax = row1_sum + row2_sum;

        for (int index = 0; index < m; index++) {
            int row1_left = row1_sum - r1_sub_sum_prefix[index];
            int row2_left = r2_sub_sum_prefix[index] - r2[index];

            int max_index = max(row1_left, row2_left);
            minmax = min(minmax, max_index);
        }

        cout << minmax << endl;




    }


    int main() {
        int t;
        cin >> t;
        for (int i = 0; i < t; ++i) {
            solve();
        }
    }