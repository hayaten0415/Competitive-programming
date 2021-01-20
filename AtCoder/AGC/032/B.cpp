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
  vector<P> ans;
  if(n % 2 == 0){
    for (int i = 1; i <= n; i++){
      for (int j = i + 1; j <= n; j++){
        if(i + j == n + 1)continue;
        ans.push_back({i, j});
      }
    }
  }else{
    for (int i = n; i > 0; i--){
      for (int j = i - 1; j > 0; j--){
        if(i != n && i + j == n)continue;
        ans.push_back({i, j});
      }
    }
  }
  cout << ans.size() << endl;
  rep(i, ans.size()){
    cout << ans[i].first << " " << ans[i].second << endl;
  }
}