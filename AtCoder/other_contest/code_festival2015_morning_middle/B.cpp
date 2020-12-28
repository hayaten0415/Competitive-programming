#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};



int main() {
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  rep(i, n){
    string t = s.substr(0, i);
    string k = s.substr(i, n);
    if(t.size() == 0 || k.size() == 0)continue;
    int d = t.size();
    int m = k.size();
    vector<vector<int>> dp(d+1, vector<int>(m+1, 0));
    rep(j, d){
      rep(c, m){
        if(t[j] == k[c]){ 
          dp[j+1][c+ 1] = dp[j][c] + 1;
        }else{ 
          dp[j+1][c+ 1] = max(dp[j+1][c], dp[j][c+1]);
        }
      }
    }
    chmax(ans, dp[d][m]);
  }
  cout << n - ans * 2 << endl;
}