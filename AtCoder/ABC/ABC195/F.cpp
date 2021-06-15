#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
  int n, m;
  cin >> n >> m;
  int n2 = (1 << n);
  vector<int> dp(n2, n);
  vector<int> s(n2, 0);
  set<P> st;
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--, b--;
    st.insert({a, b});
  }
  rep(i, n2){
    bool ok = true;
    rep(j, n) for (int d = j + 1; d < n; d++){
      if((i & (1 << j)) && ((i & (1 << d)))){
        if(st.find({j, d}) == st.end())ok = false;
      }
    }
    if(ok)s[i] = 1;
    else s[i] = popcount(i);
  }
  dp[0] = 0;
  rep(S, n2){
    //集合Sの部分集合のうち空集合は飛ばしている。
    for (int T=S; T> 0; T=(T-1)&S) {
      int rest = S ^ T;
      if(s[S] == 1){
        chmin(dp[S], 1);
      }else{
        chmin(dp[S], s[T] + dp[rest]);
      }
    }
  }
  cout << dp[n2 - 1] << endl;
}