#include <iostream>
#include <vector>

using namespace std;


void solve_case(){
    int n; 
    cin >> n;
    vector<int> input;
    input.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
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