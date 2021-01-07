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
  vector<int> L(m), R(m), X(m);
  rep(i, m){
    cin >> L[i] >> R[i] >> X[i];
    L[i]--, R[i]--;
  }
  vector<bool> ng(n, false);
  rep(i, m){
    if(X[i] == 0){
      for (int j = L[i]; j <= R[i]; j++)ng[j] = true;
    }
  }
  rep(i, m){
    if(X[i] > 0){
      int cn = 1;
      for (int j = L[i]; j <= R[i]; j++){
        if(ng[j]) cn *= 1;
        else cn *= 0;
      }
      if(cn == 1){
        cout << -1 << endl;
        return 0;
      }
    }
  }
  int ans = 0;
  for (int bit = 0; bit < (1 << n); bit++){
    int num = 0;
    rep(i, n) if (bit & (1 << i)) num++;
    bool ok = true;
    rep(j, m){
      int cn = 0;
      for (int k = L[j]; k <= R[j]; k++){
        if(bit & (1 << k))cn++;
      }
      if(cn > X[j])ok = false;
    }
    if(ok)chmax(ans, num);
  }
  cout << ans << endl;
}