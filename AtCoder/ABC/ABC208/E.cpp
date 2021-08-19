#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define fi first
#define se second
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
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
const auto INF = numeric_limits<T>::max()/2;

//ith, smaller, non-leadingzero
//[i][j][k]
map<ll, ll> dp[20][2][2];

int main() {
  ll c;
  string s;
  cin >> s >> c;
  ll ulim = c;
  int N = (int)s.size();
  dp[0][0][0][1] = 1;
  rep(i,N)rep(j,2)rep(k,2){
    //i桁目の値
    ll nd = s[i] - '0';
    for(auto f : dp[i][j][k]){
      rep(d, 10){
        ll nj = j;
        ll nk = k;
        ll p = f.fi;
        if(j == 0 && d > nd)continue;
        if(d < nd) nj = 1;
        if(d!= 0)nk = 1;
        if(nk)p *= d;
        if(p > ulim){
          p = ulim + 1;
        }
        dp[i + 1][nj][nk][p] += f.second;
      }
    }
  }
  ll ans = 0;
  rep(i, 2)for(auto f : dp[N][i][1])if(f.first <= ulim)ans += f.se;
  cout << ans << endl;
}