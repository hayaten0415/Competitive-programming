#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;
  int mx = (n-1) * (n-2) / 2;
  if(mx < k){
    cout << -1 << endl;
    return 0;
  }
  vector<P> ans;
  int num = mx - k;
  for(int i = 2; i <= n; i++){
    ans.push_back({1, i});
  }
  int add = mx - k;
  vector<P> edge;
  for (int i = 2; i < n; i++){
    for (int j = i + 1; j <= n; j++){
      edge.push_back({i, j});
    }
  }
  rep(i, add) ans.push_back(edge[i]);
  cout << ans.size() << endl;
  rep(i, ans.size()){
    cout << ans[i].first << " " << ans[i].second << endl;
  }
}