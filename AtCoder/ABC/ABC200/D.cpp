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
  int n;
  cin >> n;
  vector<int> A(n), cn(200);
  rep(i, n){
    cin >> A[i];
    A[i] %= 200;
  }
  vector<set<int>> dp(200);
  rep(i, n){
    if(dp[A[i]].size() > 0){
      cout << "Yes\n";
      cout << 1 << " ";
      for(auto s : dp[A[i]]){
        cout << s << " ";
      }
      cout << endl;
      cout << 1 << " " << i + 1 << endl;
      return 0;
    }
    dp[A[i]].insert(i+1);
  }
  rep(i, n){
    rep(m, 200){
      if(dp[m].size() == 0)continue;
      if(dp[m].find(i +1) != dp[m].end())continue;
      int nd = (A[i] + m) % 200;
      if(dp[nd].size() > 0){
        dp[m].insert(i+ 1);
        if(dp[nd] == dp[m]){
          dp[m].erase(i + 1);
          continue;
        }
        cout << "Yes\n";
        cout << dp[nd].size() << " ";
        for (auto s : dp[nd]){
          cout << s << " ";
        }
        cout << endl;
        cout << dp[m].size() << " ";
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
  cout << "No\n";
}