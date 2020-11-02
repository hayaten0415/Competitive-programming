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
  int n, m;
  cin >> n >> m;
  vector<ll> H(n), W(m);
  rep(i, n) cin >> H[i];
  rep(i, m) cin >> W[i];
  sort(ALL(H));
  sort(ALL(W));
  vector<ll> sum1((n+ 1) / 2);
  vector<ll> sum2((n + 1) / 2);
  for(int i = 0; i + 1 < n; i += 2) sum1[i / 2 + 1] = sum1[i / 2] + H[i + 1] - H[i];
  for(int i = n - 2; i > 0; i -= 2) sum2[i / 2] = sum2[i / 2 + 1] + H[i + 1] - H[i];
  ll ans = (1LL << 60);
  rep(i, m){
    int ind = lower_bound(ALL(H), W[i]) - H.begin();
    if(ind & 1) ind ^= 1;
    chmin(ans, sum1[ind / 2] + sum2[ind / 2] + abs(H[ind] - W[i]));
  }
  cout << ans << endl;
}