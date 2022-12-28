#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void solve_case(){
    vector<vector<int>> input;
    vector<int> level;
    vector<int> parent;
    
    int n; 
    cin >> n;
    input.resize(n + 1);
    parent.resize(n + 1);

    for (int i = 1; i < n; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        input[tmp1].push_back(tmp2);
        input[tmp2].push_back(tmp1);
    }

    level.resize(n+1);
    level[1] = 0;
    deque<int> queue;
    queue.push_back(1);

    vector<int> solution;
    
    if (input[1].size() < 2) {
        cout << n - 1 - input[1].size() << endl;
        return;
    }

    while (queue.size() != 0) {
        int curr_node = queue.front();
        queue.pop_front();


        // cout << curr_node << endl;
        if (input[curr_node].size() == 1) {
            // leaf
            cout << (n - 2 * level[curr_node] - 1) << endl;
            return;
        } else if (input[curr_node].size() == 2) {
            cout << (n - 2 * level[curr_node] - 2) << endl;
            return;
        }
        else {
            for (int son : input[curr_node]) {
                if (son != parent[curr_node]) {
                    queue.push_back(son);
                    // levels_queue.push_back(curr_node_level + 1);
                    parent[son] = curr_node;
                    level[son] = level[curr_node] + 1;
                }
            }
        }
    }
    cout << endl;
}



int main()
{
    int numTestCases; 
    cin >> numTestCases;
    
    for (int i = 0; i < numTestCases; ++i) {
        solve_case();
    }
    
}

