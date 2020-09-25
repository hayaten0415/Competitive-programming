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
  string s;
  cin >> s;
  int n = s.size();
  int ans = n;
  for (int bit = 1; bit < (1 << n); bit += 2){
    vector<bool> ok(n, false);
    bool all = true;
    int num = __builtin_popcount(bit);
    rep(i, n){
      if(bit & (1 << i)){
        rep(j, n){
          if (s[j % n] == 'o'){
            ok[(j + i) % n] = true;
          }
        }
      }
    }
    rep(i, n){
      if(!ok[i])all = false;
    }
    if(all){
      ans = min(ans, num);
    }
  }
  cout << ans << endl;
}