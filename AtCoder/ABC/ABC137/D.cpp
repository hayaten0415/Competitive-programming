#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> work(m, vector<int>(0));
  ll ans = 0;
  rep(i, n){
    int a, b;
    cin >> a >> b;
    if(a > m)continue;
    a--;
    work[a].push_back(b);
  }
  priority_queue<int> que;
  rep(i, m){
    rep(j,work[i].size()){
      que.push(work[i][j]);
    }
    if(!que.empty()){
      ans += que.top();que.pop();
    }
  }
  cout << ans << endl;
}