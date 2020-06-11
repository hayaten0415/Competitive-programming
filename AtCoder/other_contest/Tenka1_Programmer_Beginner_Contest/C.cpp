#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int ans = n;
  vector<int> white_sum(n+1, 0);
  vector<int> black_sum(n+1, 0);
  rep(i, n){
    if(s[i] == '#'){
      black_sum[i + 1] = black_sum[i] + 1;
    }else{
      black_sum[i + 1] = black_sum[i];
    }
  }
  for (int i = n - 1; i >= 0; i--){
    if(s[i] == '.'){
      white_sum[i] = white_sum[i + 1] + 1;
    }else {
      white_sum[i] = white_sum[i + 1];
    }
  }
  rep(i, n+1){
    ans = min(ans, white_sum[i] + black_sum[i]);
  }
  cout << ans << endl;
}
