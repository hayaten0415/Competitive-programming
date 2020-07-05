#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  vector<int> ans(n);
  rep(t, 2){
    int cn = 0;
    rep(i, n){
      if(s[i] == 'R')cn++;
      else{
        ans[i] += cn / 2;
        ans[i - 1] += (cn + 1) / 2;
        cn = 0;
      }
    }
    reverse(ans.begin(), ans.end());
    reverse(s.begin(), s.end());
    rep(i, n){
      if(s[i] == 'R') s[i] ='L';
      else s[i] = 'R';
    }
  }
  rep(i, n) cout << ans[i] << (i == n - 1 ? "\n" : " ");
}