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
  vector<int> sum(n, 0);
  vector<int> pos(k);
  rep(i, n - 1) cin >> sum[i + 1];
  rep(i, k) cin >> pos[i];
  rep(i,n-1){
    sum[i + 1] = sum[i] + sum[i+1];
  }
  ll ans = 0;
  int now = 0;
  rep(i, k){
    if(pos[i] > 0){
      ans += sum[now+pos[i]] - sum[now];
    }else{
      ans += sum[now] - sum[now + pos[i]];
    }
    now += pos[i];
  }
  cout << ans % 100000 << endl;
}