#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
string S[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int main() {
  string s;
  int num = 0;
  cin >> s;
  rep(i, 7) {
    if(s == S[i]) {
      num = i;
    }
  }
  cout << 7 - num << endl;
  return 0;
}