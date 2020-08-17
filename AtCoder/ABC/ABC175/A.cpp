#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  int num = 0;
  int ans = 0;
  rep(i, 3) {
    if(s[i] == 'R'){
      num++;
    }else{
      ans = max(num,ans);
      num = 0;
    }
  }
  ans = max(num,ans);
  cout << ans << endl;
}