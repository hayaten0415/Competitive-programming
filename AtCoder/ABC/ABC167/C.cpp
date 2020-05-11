#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;
const int INF = 100000000;

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> money(n);
  vector<vector<int>> under(n, vector<int>(m, 0));
  rep(i, n){
    cin >> money[i];
    rep(j,m){
      cin >> under[i][j];
    }
  }
  int ans = INF;
  for (int bit = 0; bit < (1 << n); bit++){
    int tmp_money = 0;
    vector<int> under1(m);
    for (int i = 0; i < n; i++){
      if (bit & (1 << i)){
        tmp_money += money[i];
        rep(j,m){
          under1[j] += under[i][j];
        }
      }
    }
    rep(i,m){
      if(under1[i] >= x){
        if(i == m-1){
          ans = min(ans, tmp_money);
        }
      }else {
        break;
      }
    }
  }
  if(ans == INF){
    cout << -1 << endl;
  }else {
    cout << ans << endl;
  }
}