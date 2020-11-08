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
  int N, M;
  cin >> N >> M;
  ll ans = (1LL << 60);
  ans *= -1;
  vector<ll> X(N), Y(N), Z(N);
  rep(i, N) cin >> X[i] >> Y[i] >> Z[i];
  rep(i, 2)rep(j, 2)rep(k, 2){
    vector<ll> tmp(N);
    rep(s, N){
      ll x = X[s];
      ll y = Y[s];
      ll z = Z[s];
      if(i == 1)x *= -1;
      if(j == 1)y *= -1;
      if(k == 1)z *= -1;
      tmp[s] = x + y + z;
    }
    sort(ALL(tmp), greater<ll>());
    ll tmp_sum = 0;
    rep(s, M){
      tmp_sum += tmp[s];
    }
    chmax(ans, tmp_sum);
  }
  cout << ans << endl;
}