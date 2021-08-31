#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
const auto INF = numeric_limits<T>::max() / 5;

ll dp[10];

void solve() {
  ll n;
  cin >> n;
  int sum = 0;
  dp[0] = 0;
  rep(i, 9) dp[i + 1] = -INF<ll>;
  rep(i, n){
    ll k;
    cin >> k;
    ll dp2[10];
    vector<ll> v1(3, -INF<ll>), v2(1, -INF<ll>), v3(1, -INF<ll>);
    rep(j,k){
      int c,d;
      cin>>c>>d;
      if(c==1)v1.eb(d);
      if(c==2)v2.eb(d);
      if(c==3)v3.eb(d);
    }
    sort(ALL(v1), greater{});
    sort(ALL(v2), greater{});
    sort(ALL(v3), greater{});
    rep(j,10){
      dp2[j] = dp[j];
    }
    rep(j,10){
      chmax(dp2[(j+1)%10],dp[j]+(j==9?2:1)*max({v3[0],v2[0],v1[0]}));
    }
    rep(j,10){
      chmax(dp2[(j+2)%10],dp[j]+v1[0]+v1[1]+(j>=8?v1[0]:0));
      chmax(dp2[(j+2)%10],dp[j]+v1[0]+v2[0]+(j>=8?max(v1[0],v2[0]):0));
    }
    rep(j,10){
      chmax(dp2[(j+3)%10],dp[j]+v1[0]+v1[1]+v1[2]+(j>=7?v1[0]:0));
    }
    swap(dp, dp2);
  }
  ll ans = 0;
  rep(i,10)chmax(ans,dp[i]);
  cout<<ans<<endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}