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
  int A, B, Q;
  cin >> A >> B >> Q;
  vector<ll> s(A), t(B), q(Q), ans(Q, INF);
  rep(i, A) cin >> s[i];
  rep(i, B) cin >> t[i];
  rep(i, Q) cin >> q[i];
  rep(i, Q){
    int k = lower_bound(ALL(s), q[i]) - s.begin();
    int j = lower_bound(ALL(t), q[i]) - t.begin();
    if(k < A && j < B){
      chmin(ans[i], max(s[k], t[j]) - q[i]);
    }
    if(k < A && j > 0){
      chmin(ans[i], abs(s[k]- t[j-1]) * 2 - max(abs(q[i]- s[k]), abs(q[i]- t[j-1])));
    }
    if(k > 0 && j < B){
      chmin(ans[i], abs(s[k-1] - t[j]) * 2 - max(abs(q[i] - s[k-1]), abs(q[i] - t[j])));
    }
    if(k > 0 && j > 0){
      chmin(ans[i], q[i] - min(s[k-1], t[j-1]));
    }
  }
  rep(i, Q){
    cout << ans[i] << endl;
  }
}