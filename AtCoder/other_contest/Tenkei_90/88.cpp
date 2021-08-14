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
  int n, q;
  cin >> n >> q;
  vector<int> A(n);
  //vector<P> Q(q);
  vector<set<int>> G(n);
  rep(i, n){
    cin >> A[i];
  }
  int sum = accumulate(ALL(A), 0);
  rep(i, q){
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].insert(b);
    G[b].insert(a);
  }
  vector<set<int>> dp(sum + 1);
  rep(i, n){
    if(dp[A[i]].size() > 0){
      cout << 1 << endl;
      for(auto s : dp[A[i]]){
        cout << s << " ";
      }
      cout << endl;
      cout << 1 << endl;
      cout << i + 1 << endl;
      return 0;
    }
    dp[A[i]].insert(i+1);
  }
  rep(i, n){
    rep(m, sum + 1){
      if(dp[m].size() == 0)continue;
      if(dp[m].find(i +1) != dp[m].end())continue;
      int nd = A[i] + m;
      if(nd > sum)break;
      bool cond = true;
      for(auto b : dp[m]){
        if(G[b-1].find(i) != G[b-1].end()){
          cond = false;
        }
      }
      if(!cond)continue;
      if(dp[nd].size() > 0){
        dp[m].insert(i + 1);
        if(dp[nd] == dp[m]){
          dp[m].erase(i + 1);
          continue;
        }
        cout << dp[nd].size() << endl;
        for (auto s : dp[nd]){
          cout << s << " ";
        }
        cout << endl;
        cout << dp[m].size() << endl;
        for (auto s : dp[m]){
          cout << s << " ";
        }
        cout << endl;
        return 0;
      }else{
        dp[nd] = dp[m];
        dp[nd].insert(i + 1);
      }
    }
  }
}