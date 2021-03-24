#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using P = pair<long long, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};


void solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> A(n), X(m);
  rep(i, n) cin >> A[i];
  ll sum_All = 0;
  vector<ll> pre;
  vector<int> ind;
  rep(i, n){
    sum_All += A[i];
    if(pre.empty() || sum_All> pre.back()){
      pre.pb(sum_All);
      ind.pb(i);
    }
  }
  rep(i, m){
    ll x;
    cin >> x;
    if(pre.back() < x && sum_All <= 0){
      cout << -1 << " ";
      continue;
    }
    ll time = 0;
    if(pre.back() < x){
      time = (x - pre.back() + sum_All - 1) / sum_All;
    }
    x -= time * sum_All;
    cout << time * n + ind[lower_bound(ALL(pre), x) - pre.begin()] << " ";
  }
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}