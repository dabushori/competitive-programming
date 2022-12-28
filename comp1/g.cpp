#include <iostream>

using namespace std;


void solve_case(){
    int num; 
    cin >> num;
    
    int b = num % 11;

    if (num >= 111 * b) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return;
}


int main()
{
    int numTestCases; 
    cin >> numTestCases;
    
    for (int i = 0; i < numTestCases; i++) {
        solve_case();      
    }
}
