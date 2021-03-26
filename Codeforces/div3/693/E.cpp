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
using PP = pair<P, int>;
typedef long long ll;
typedef pair<ll, ll> l_l;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const long long INF = 1e18;

void solve() {
    ll N;
    cin >> N;
    vector<l_l> v(N);
    for(int i = 0; i < N; i++) {
      cin >> v[i].first >> v[i].second;
      if(v[i].first > v[i].second) swap(v[i].first, v[i].second);
    }
    vector<ll> idx(N);
    for(int i = 0; i < N; i++) {
        idx[i] = i;
    }
    sort(idx.begin(), idx.end(), [&](ll a, ll b){
        if(v[a].first != v[b].first) return v[a].first < v[b].first;
        return v[a].second > v[b].second;
    });
    ll minval = INF;
    ll minidx = -1;
    vector<ll> ans(N);
    for(auto tmp : idx) {
      if(v[tmp].second > minval) {
        ans[tmp] = minidx;
      } else {
        ans[tmp] = -2;
      }
      if(chmin(minval, v[tmp].second)) {
        minidx = tmp;
      }
    }
    for(int i = 0; i < N; i++) {
      if(i != 0) cout << " ";
      cout << ans[i] + 1;
    }
    cout << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}