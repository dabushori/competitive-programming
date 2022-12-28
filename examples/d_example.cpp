#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> g;
vector<int> v;

void dfs(int cur){
    v[cur] = 1;
    for(int i = 0; i < g[cur].size(); i++){
        int nei = g[cur][i];
        if(v[nei] == 0){
            dfs(nei);
        }
    }
}

int32_t main(){
    int n,m;
    cin >> n >> m;
    g.resize(n+1);
    v.resize(n+1,0);
    for(int i = 0; i < m; i++){
        int tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        g[tmp1].push_back(tmp2);
        g[tmp2].push_back(tmp1);
    }

    dfs(1);
    vector<int> output;
    for(int i = 2; i < n+1; i++){
        if(v[i] == 0){
            dfs(i);
            output.push_back(i);
        }
    }

    cout << output.size() << endl;
    for(int i = 0; i < output.size(); i++){
        cout << "1 " << output[i] << endl;
    }
    return 0;
}