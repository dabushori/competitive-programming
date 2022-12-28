    #include <iostream>
    #include <stdint.h>

    #include <vector>
    #include <utility>

    using namespace std;

    #define int int64_t
    #define vb vector<bool>
    #define vi vector<int>
    #define vvi vector<vi>
    #define ii pair<int, int>


    int n;
    vector<vi> edges;
    vi parents;
    vi citizens;

    vi citizens_in_sub_tree;

    vi leafs_in_sub_tree;

    void calc_citizens_in_sub_trees(int i) {
        citizens_in_sub_tree[i] = citizens[i];
        for (int subnode : edges[i]) {
            calc_citizens_in_sub_trees(subnode);
            citizens_in_sub_tree[i] += citizens_in_sub_tree[subnode];
        }
    }

    void calc_number_of_leafs(int i) {
        if (edges[i].size() == 0) {
            leafs_in_sub_tree[i] = 1;
        } else {
            leafs_in_sub_tree[i] = 0;
        }
        for (int subnode : edges[i]) {
            calc_number_of_leafs(subnode);
            leafs_in_sub_tree[i] += leafs_in_sub_tree[subnode];
        }

    }

    void solve() {
        cin >> n;

        edges.resize(n + 1);
        citizens.resize(n + 1);
        parents.resize(n + 1);
        citizens_in_sub_tree.resize(n + 1);
        leafs_in_sub_tree.resize(n + 1);

        int tmp;
        for (int i = 2; i <= n; ++i) {
            cin >> tmp;
            edges[tmp].push_back(i);
            parents[i] = tmp;
        }

        for (int i = 1; i <= n; ++i) {
            cin >> tmp;
            citizens[i] = tmp;
        }
        
        calc_citizens_in_sub_trees(1);
        calc_number_of_leafs(1);

        int max_arb = 0;
        for (int i = 1; i <= n; i++) {
            int cit = citizens_in_sub_tree[i];
            int leafs = leafs_in_sub_tree[i];
            int arb =  cit / leafs + ((cit % leafs) != 0);
            if (arb > max_arb) { 
                max_arb = arb;
            }
        }

        cout << max_arb << endl;
    }

int32_t main() {
    solve();
}