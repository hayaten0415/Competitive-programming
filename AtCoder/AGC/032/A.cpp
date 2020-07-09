#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;


int main() {
  int n;
  cin >> n;
  vector<int> b(n);
  vector<bool> flag(n,true);
  vector<int> ans;
  rep(i, n) cin >> b[i];
  rep(i, n){
    int cn = 0;
    int num = -1;
    rep(j, n){
      if(flag[j])cn++;
      if(b[j] == cn)num = j;
    }
    if(num != -1){
      flag[num] = false;
      ans.push_back(b[num]);
    }
  }
  rep(i, n){
    if(flag[i]){
      cout << -1 << endl;
      return 0;
    }
  }
  reverse(ans.begin(), ans.end());
  rep(i, n){
    cout << ans[i] << endl;
  }
}