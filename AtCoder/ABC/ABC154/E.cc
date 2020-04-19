#include <iostream>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int dp[103][4][2];
//dp[i][j][k]
// i桁目まで決めてj個の0を使って
// k=0 そこまでの行はNと一致
// k=1そこまでの行ですでにN以下であることが確定


int main(){
  string s;
  cin >> s;
  int n = s.size();
  int K;
  cin >> K;
  dp[0][0][0] = 1;
  rep(i,n)rep(j,4)rep(k,2){
    //i桁目の値
    int nd = s[i] - '0';
    rep(d, 10){
      int ni = i + 1, nj = j, nk = k;
      //0でなければ次へ
      if(d != 0) nj++;
      if(nj > K) continue;
      if(k == 0){
        if(d > nd) continue;
        if(d < nd) nk = 1;
      }
      dp[ni][nj][nk] += dp[i][j][k];
    }
  }
  int ans = dp[n][K][0] + dp[n][K][1];
  cout << ans << endl;
  return 0;
}
