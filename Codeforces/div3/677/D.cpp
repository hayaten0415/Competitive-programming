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


void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  vector<int> ok(n, 0);
  vector<P> ans;
  rep(i, n) cin >> A[i];
  int f = -1;
  for (int j = 1; j < n; j++){
    if(ans.size() == n-1)break;
    if(A[0] == A[j])continue;
    ans.pb({1, j + 1});
    f = j+1;
  }

  rep(i, n){
    if(i ==0)continue;
    if(ans.size() == n-1)break;
    if(A[0] == A[i])ans.eb(i+ 1, f);
  }
  if(f == -1){
    cout << "NO" << endl;
  }else{
    cout << "YES" << endl;
    for(auto [a, b] : ans){
      cout << a << " " << b << endl;
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}