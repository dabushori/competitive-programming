#include <iostream>
#include <map>
 
using namespace std;

 
int main()
{
    map<int, int> m;
    m[2] = 3;
    for(int i = 1; i <= 3 ; i++){
        if(m.find(i) == m.end()){
            cout << "NO key: " << i << endl;
        }
        else{
            cout << "Key " << i << ", have val: " << m[i] << endl; 
        }
    }

    return 0;
}