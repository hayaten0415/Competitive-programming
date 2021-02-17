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

ll dp[1001][1001];

int main() {
  int A, B;
  cin >> A >> B;
  vector<int> a(A), b(B);
  rep(i, A) cin >> a[i];
  rep(i, B) cin >> b[i];
  dp[A][B] = 0;
  rrep(i, A+1){
    rrep(j, B+1){
      if(i == A && j == B)continue;
      if((i + j) % 2 == 0){
        if(i == A){
          dp[i][j] = dp[i][j+1] + b[j];
        }else if(j == B){
          dp[i][j] = dp[i+1][j] + a[i];
        }else{
          dp[i][j] = max(dp[i][j + 1] + b[j], dp[i + 1][j] + a[i]);
        }
      }else{
        if(i == A){
          dp[i][j] = dp[i][j+1];
        }else if(j == B){
          dp[i][j] = dp[i+1][j];
        }else{
          dp[i][j] = min(dp[i][j + 1], dp[i + 1][j]);
        }
      }
    }
  }
  cout << dp[0][0] << endl;
}