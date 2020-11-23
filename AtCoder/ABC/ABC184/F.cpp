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
  int n;
  ll t;
  cin >> n >> t;
  vector<ll> A(n, 0);
  rep(i, n) cin >> A[i];
  vector<ll> B,C, D, E;
  B.emplace_back(0);
  C.emplace_back(0);
  rep(i, n){
    if(i % 2 == 0){
      B.emplace_back(A[i]);
    }else{
      C.emplace_back(A[i]);
    }
  }
  int s = B.size();
  int m = C.size();
  for (int bit = 0; bit < (1 << s); bit++){
    ll num = 0;
    rep(i, s){
      if(bit & (1 << i)){
        num += B[i];
      }
    }
    D.emplace_back(num);
  }
  for (int bit = 0; bit < (1 << m); bit++){
    ll num = 0;
    rep(i, m){
      if(bit & (1 << i)){
        num += C[i];
      }
    }
    E.emplace_back(num);
  }
  int cn = D.size();
  sort(ALL(E));
  ll ans =  0;
  rep(i,cn){
    if(D[i] > t)continue;
    int k = upper_bound(ALL(E), t - D[i]) - E.begin();
    if(k > 0)k--;
    if(D[i] + E[k] > t)continue;
    chmax(ans, D[i] + E[k]);
  }
  cout << ans << endl;
}