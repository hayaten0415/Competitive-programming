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
  int a, b;
  cin >> a >> b;
  vector<vector<int>> dp(b, vector<int>(a, 0));
  int n;
  cin >> n;
  set<P> st;
  rep(i, n){
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    st.insert({y, x});
    dp[y][x] = 0;
  }
  if(st.find({0, 0}) != st.end() || st.find({0, 0}) != st.end()){
    cout << 0 << endl;
    return 0;
  }
  dp[0][0] = 1;
  rep(i,a-1){
    if(st.find({0, i+1}) != st.end())continue;
    dp[0][i + 1] = dp[0][i];
  }
  rep(i,b-1){
    if(st.find({i+1, 0}) != st.end())continue;
    dp[i+1][0] = dp[i][0];
  }
  for(int i = 1; i <= a-1; i++){
    for (int j = 1; j <= b-1; j++){
      if(st.find({j, i}) != st.end())continue;
      dp[j][i] += dp[j - 1][i] + dp[j][i - 1];
    }
  }
  cout << dp[b-1][a-1] << endl;
}