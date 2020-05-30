#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  int i = 0;
  while (i + 1 < s.size()){
    if(s[i] == s[i+1]){
      cout << i + 1 << " " << i + 2 << endl;
      return 0;
    }
    if(i + 2 < s.size() && s[i] == s[i+2]){
      cout << i + 1 << " " << i + 3 << endl;
      return 0;
    }
    i++;
  }
  cout << -1 << " " << -1 << endl;
}