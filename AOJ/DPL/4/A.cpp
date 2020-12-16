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
  ll V;
  cin >> n >> V;
  vector<ll> A(n), B(n), C(n), D(n);
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> B[i];
  rep(i, n) cin >> C[i];
  rep(i, n) cin >> D[i];
  vector<ll> AB, CD;
  rep(i, n)rep(j, n){
    AB.emplace_back(A[i] + B[j]);
    CD.emplace_back(C[i] + D[j]);
  }
  ll ans = 0;
  sort(ALL(CD));
  rep(i, n * n){
    if(AB[i] >= V)continue;
    int mx = upper_bound(ALL(CD), V - AB[i]) - CD.begin();
    int mn = lower_bound(ALL(CD), V - AB[i]) - CD.begin();
    ans += mx - mn;
  }
  cout << ans << endl;
}