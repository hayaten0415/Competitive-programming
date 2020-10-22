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

vector<int> w;
vector<vector<int>> dp;

int dfs(int l, int r){
  if(r - l <=1)return 0;
  if(r- l == 2){
    if(abs(w[l] - w[l+1]) <= 1){
      return 2;
    }else{
      return 0;
    }
  }
  int &ret = dp[l][r];
  if(ret != -1)return dp[l][r];
  if (abs(w[l] - w[r-1]) <= 1 && dfs(l + 1, r - 1) == r - l - 2) chmax(ret, r - l);
  for (int i = l + 1; i < r; i++) {
    chmax(ret, dfs(l, i) + dfs(i, r));
  }
  return ret;
}

int main() {
  vector<int> ans;
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    w.resize(n);
    rep(i, n) cin >> w[i];
    dp.assign(n + 2, vector<int>(n + 2, -1));
    ans.push_back(dfs(0, n));
  }
  for (auto i: ans){
    cout << i << endl;
  }
}