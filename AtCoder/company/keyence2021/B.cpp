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
  int n, k;
  cin >> n >> k;
  vector<int> A(n), cnt(n);
  vector<int> mn(n);
  mn[0] = k;
  rep(i, n){
    cin >> A[i];
    cnt[A[i]]++;
  }
  int tmp_mn = k;
  int ans = 0;
  rep(i, n){
    if(tmp_mn > cnt[i]){
      ans += (tmp_mn - cnt[i]) * i;
      tmp_mn = cnt[i];
    }
  }
  cout << ans << endl;
}