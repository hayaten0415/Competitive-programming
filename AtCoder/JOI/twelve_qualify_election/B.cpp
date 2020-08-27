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
  cin >> n;
  vector<int> ans(n, 0);
  vector<map<int, int>> mp(3);
  vector<vector<int>> num(n, vector<int>(3));
  rep(i, n){
    rep(j, 3){
      cin >> num[i][j];
      mp[j][num[i][j]]++;
    }
  }
  rep(i, n){
    rep(j, 3){
      if(mp[j][num[i][j]] > 1)continue;
      ans[i] += num[i][j];
    }
  }
  rep(i, n){
    cout << ans[i] << "\n";
  }
}