#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

// if string s is a divisor of string t
bool isDivisor(const std::string& s, const std::string& t) {
  if (s.empty() || t.empty()) return false; 
  if (s.size() > t.size()) return false;
  int x = t.size() / s.size();
  std::string concatenated;
  for (int i = 0; i < x; i++) {
    concatenated += s;
  }
  return concatenated == t;
}

set<string> solve_case(string t) {
    set<string> divisors;
    for (int len = 1; len <= t.size(); len++) {
        std::string s = t.substr(0, len);
        if (isDivisor(s, t)) {
            divisors.insert(s);
      }
    }
    return divisors;
}

int gcd(int a, int b) {
  while (b > 0) {
    int tmp = b;
    b = a % b;
    a = tmp;
  }
  return a;
}

int solve(string s1, string s2) {
  int count = 0;
  int len1 = s1.length();
  int len2 = s2.length();

  int g = gcd(len1, len2);


  for (int len = 1; len <= len1; len++) {
      if (g % len != 0) {
        continue;
      }
      std::string s = s1.substr(0, len);
      if (isDivisor(s, s1) && isDivisor(s, s2)) {
          count++;
    }
  }

  return count;
}

int main() {
  std::string s1;
  std::cin >> s1;
  std::string s2;
  std::cin >> s2;
  // set<string> divisorS1 = solve_case(s1);
  // set<string> divisorS2 = solve_case(s2);
  // set<string> intersect;
  // set_intersection(divisorS1.begin(), divisorS1.end(), divisorS2.begin(), divisorS2.end(),std::inserter(intersect, intersect.begin()));
  // for(string s: intersect) {
  //     cout << s << " ";
  // }

  cout << solve(s1, s2) << endl;
  // cout<<intersect.size()<<endl;
  return 0;
}

/*
input:
abcdabcd
abcdabcdabcdabcd
1 ms

input:
aaa
aa

*/