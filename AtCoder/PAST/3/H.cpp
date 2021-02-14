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
const ll INF = (1LL << 60);

int main() {
  int n, L;
  cin >> n >> L;
  vector<ll> dp(L + 1, INF);
  vector<bool> hardle(L + 1, false);
  dp[0] = 0;
  rep(i, n){
    int a;
    cin >> a;
    hardle[a] = true;
  }
  ll t1,t2,t3;
  cin >>t1 >> t2 >> t3;
  for (int i = 1; i <= L; i++){
    if(!hardle[i]){
      chmin(dp[i], dp[i - 1] + t1);
      if(i >1)chmin(dp[i], dp[i-2] + t1 + t2);
      if(i >3)chmin(dp[i], dp[i-4] + t1 + t2 * 3);
    }else{
      chmin(dp[i], dp[i - 1] + t1 + t3);
      if(i >1)chmin(dp[i], dp[i-2] + t1 + t2 + t3);
      if(i >3)chmin(dp[i], dp[i-4] + t1 + t2 * 3 + t3);
    }
  }
  chmin(dp[L], dp[L-1] + (t1/ 2) + (t2 / 2));
  chmin(dp[L], dp[L-2] + (t1/ 2) + t2 + (t2/ 2));
  if(L >= 3)chmin(dp[L], dp[L-3] + (t1/ 2) + t2 * 2 + (t2/ 2));
  cout << dp[L] << endl;
}