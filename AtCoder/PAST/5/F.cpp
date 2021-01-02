#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> comb(m, vector<int>(3));
  rep(i, m){
    rep(j, 3){
      cin >> comb[i][j];
      comb[i][j]--;
    }
  }
  int ans = 0;
  for (int bit = 0; bit < (1 << n); bit++){
    if(__builtin_popcount(bit) < 2)continue;
    set<int> st;
    set<int> res;
    rep(i, n){
      if(bit & (1 << i)){
        st.insert(i);
      }
    }
    bool ok = true;
    rep(i, m){
      int num = 0;
      int bomb = -1;
      rep(j, 3){
        if(st.find(comb[i][j]) == st.end()){
          bomb = comb[i][j];
          num++;
        }
      }
      if(num > 1)continue;
      if(num == 0)ok = false;
      if(num == 1){
        res.insert(bomb);
      }
    }
    if(ok){
      chmax(ans, (int)res.size());
    }
  }
  cout << ans << endl;
}