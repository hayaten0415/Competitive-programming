#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
using namespace std;
using P = pair<int, int>;
using PL = pair<long long, long long>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll INF = (1LL << 60);

vector<ll> d(1e7 + 1, 0);
vector<ll> ans(1e7 + 1, INF);

void solve() {
  ll c;
  cin >> c;
  if(ans[c] == INF){
    cout << -1 << endl;
  }else{
    cout << ans[c] << endl;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  for(ll i = 1; i <= 1e7; i++){
    for (int j = i; j <= 1e7; j += i){
      d[j] += i;
    }
  }
  for(ll i = 1; i <= 1e7; i++){
    if(d[i] > 1e7)continue;
    chmin(ans[d[i]], i);
  }
  int t;
  cin >> t;
  while(t--) solve();
}