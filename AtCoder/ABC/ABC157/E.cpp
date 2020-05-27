#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, q;
  string s;
  cin >> n >> s >> q;
  vector<set<int>> is(26);
  rep(i, n) is[s[i] - 'a'].insert(i);
  rep(qi, q){
    int t;
    cin >> t;
    if(t ==1){
      int i;
      char c;
      cin >> i >> c;
      i--;
      is[s[i] - 'a'].erase(i);
      s[i] = c;
      is[s[i] - 'a'].insert(i);
    }else {
      int l, r;
      cin >> l >> r;
      l--;
      int ans = 0;
      rep(i,26){
        auto it = is[i].lower_bound(l);
        if(it != is[i].end() && *it < r)ans++;
      }
      cout << ans << endl;
    }
  }
}