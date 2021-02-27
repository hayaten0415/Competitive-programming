#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int n, t;
  cin >> n >> t;
  vector<int> A(n);
  vector<int> Accu_min(n);
  rep(i, n) cin >> A[i];
  Accu_min[0] = A[0];
  if(n == 1){
    cout << 0 << endl;
    return 0;
  }
  int max_profit = 0;
  int ans = 1;
  for (int i = 1; i < n; i++){
    Accu_min[i] = min(Accu_min[i - 1], A[i]);
    if(chmax(max_profit, A[i] - Accu_min[i])){
      ans = 1;
    }else if(max_profit == (A[i] - Accu_min[i])){
      ans++;
    }
  }
  cout << ans << endl;
}