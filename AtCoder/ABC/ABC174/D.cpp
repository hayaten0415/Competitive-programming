#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int num = 0;
  int w = 0;
  int r = 0;
  rep(i,n-1){
    if(s[i] == 'W' && s[i+ 1] == 'R')num++;
  }
  if(num == 0){
    cout << 0 << endl;
    return 0;
  }
  rep(i, n){
    if(s[i] == 'W')w++;
    else r++;
  }
  int ans = 0;
  rep(i, r){
    if(s[i] == 'W')ans++; 
  }
  cout << ans << endl;
}