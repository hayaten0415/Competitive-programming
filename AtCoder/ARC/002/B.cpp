#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;
const string command[4] = {"A", "B", "X", "Y"};

int solve(string s, string a, string b) {
  int cn = 0;
  rep(i, s.size()){
    if(i + 1 < s.size() && s[i] == a[0] && s[i+1] == a[1]){
      i++;
    }else if(i + 1 < s.size() && s[i] == b[0] && s[i+1] == b[1]){
      i++;
    }
    cn++;
  }
  return cn;
}

int main() {
  int n;
  string s;
  cin >> n >> s;
  int ans = n;
  rep(a,4){
    rep(b,4){
      rep(c,4){
        rep(d,4){
          string x = command[a] + command[b];
          string y = command[c] + command[d];
          if(x== y) continue;
          ans = min(ans,solve(s, x, y));
        }
      }
    }
  }
  cout << ans << endl;
}