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

int main() {
  int n;
  cin >> n;
  vector<ll> A(n), sum(n + 1, 0);
  rep(i, n) cin >> A[i];
  sort(ALL(A));
  rep(i, n){
    sum[i + 1] = sum[i] + A[i];
  }
  int minus = 0;
  for (int i = 1; i < n; i++){
    if(sum[i] * 2 >= A[i])continue;
    minus = i;
  }
  cout << n - minus << endl;
}