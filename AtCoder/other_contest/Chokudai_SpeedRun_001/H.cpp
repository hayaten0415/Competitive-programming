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

const int INF = (1 << 30);

int LIS(vector<int> &A){
  int n = A.size();
  vector<int> dp(n, INF);
  rep(i, n){
    auto it = lower_bound(ALL(dp), A[i]);
    *it = A[i];
  }
  return lower_bound(ALL(dp), INF) - dp.begin();
}


int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  int ans = LIS(A);
  cout << ans << endl;
}