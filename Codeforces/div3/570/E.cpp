#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define fi first
#define se second
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
using namespace std;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
template <typename T>
const auto INF = numeric_limits<T>::max() / 2;

vector<vector<int> > calcNext(const string &S) {
    int n = (int)S.size();
    vector<vector<int> > res(n+1, vector<int>(26, n));
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) res[i][j] = res[i+1][j];
        res[i][S[i]-'a'] = i;
    }
    return res;
}

void solve() {
  int n;
  ll k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
  vector<vector<int>> next = calcNext(s);
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 26; ++j) {
      if (next[i][j] >= n) continue; // 次の文字 j がもうない場合はスルー
      rep(k, n){
        dp[next[i][j] + 1][k+1] += dp[i][k];
      }
    }
  }
  vector<ll> res(n + 1);
  rep(i, n + 1) rep(j, n + 1) res[j] += dp[i][j];
  ll ans = 0;
  rrep(i, n+1){
    ans += min(k, res[i]) * (n - i);
    k -= min(k, res[i]);
    if(k ==0)break;
  }
  if(k > 0){
    cout << -1 << endl;
  }else{
    cout << ans << endl;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}