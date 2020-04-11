#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n, k, r, s, p;
  string t;
  cin >> n >> k >> r >> s >> p >> t;
  ll ans = 0;
  rep(i,t.size()){
    if(t[i]=='r') ans += p;
    if(t[i]== 's') ans += r;
    if(t[i]== 'p') ans += s;
  }
  for (int i = k; i < t.size(); i++){
    if (t[i] == t[i - k]){
      if(t[i]=='r') ans -= p;
      if(t[i]== 's') ans -= r;
      if(t[i]== 'p') ans -= s;
      t[i] = 'n';
    }
  }
  cout << ans << endl;
}