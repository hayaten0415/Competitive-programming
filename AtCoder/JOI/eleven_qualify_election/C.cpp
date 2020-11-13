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

int dp[1000001];

int main() {
  int N, A, B, C;
  cin >> N >> A >> B >> C;
  vector<int> D(N);
  rep(i, N) cin >> D[i];
  sort(ALL(D), greater<int>());
  vector<int> SUM_D(N+1, 0);
  SUM_D[0] = C;
  rep(i, N){
    SUM_D[i + 1] = SUM_D[i] + D[i];
  }
  int ans = 0;
  for (int i = 0; i <= N;i++){
    chmax(ans, SUM_D[i] / (A + (B * i)));
  }
  cout << ans << endl;
}