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
  vector<ll> A(n), B(n), C(m), D(m);
  vector<int> ans(n, 1);
  rep(i, n) cin >> A[i] >> B[i];
  rep(i, m) cin >> C[i] >> D[i];
  rep(i, n){
    ll dist = (1LL << 60);
    rep(j, m){
      if(chmin(dist, abs(A[i] - C[j]) + abs(B[i] - D[j]))){
        ans[i] = j+1;
      }
    }
  }
  rep(i, n){
    cout << ans[i] << endl;
  }
}