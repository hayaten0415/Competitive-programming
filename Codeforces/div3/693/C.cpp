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
  int t;
  cin >> t;
  rep(i, t){
    int n;
    cin >> n;
    vector<ll> A(n);
    vector<bool> visited(n, false);
    ll ans = 0;
    rep(i, n) cin >> A[i];
    rep(i, n){
      if(visited[i])continue;
      ll now = i;
      ll tmp = 0;
      while (now < n){
        if(visited[now])break;
        visited[now] = true;
        tmp += A[now];
        now += A[now];
      }
      chmax(ans, tmp);
    }
    cout << ans << endl;
  }
}