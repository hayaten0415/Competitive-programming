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
#define popcount(bit) __builtin_popcount(bit)
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


void solve() {
  int n;
  cin >> n;
  vector<int> ans(n);
  vector<bool> ok(n);
  vector<int> ind;
  vector<int> rest;
  rep(i, n){
    cin >> ans[i];
    ans[i]--;
    if(ans[i] != -1){
      ok[ans[i]] = true;
    }else{
      ind.pb(i);
    }
  }
  rep(i, n){
    if(!ok[i])rest.pb(i);
  }
  sort(ALL(rest));
  int c = rest.size();
  while(true){
    int k = rand() % c;
    bool ok = true;
    rep(i, c){
      ans[ind[i]] = rest[(i + k) % c];
      if(ans[ind[i]] == ind[i]){
        ok = false;
        break;
      }
    }
    if(ok){
      rep(i, n){
        cout << ans[i] + 1 << (i == n - 1 ? "\n" : " ");
      }
      return;
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  t = 1;
  while(t--) solve();
}