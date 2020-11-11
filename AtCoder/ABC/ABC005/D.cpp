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
  vector<vector<ll>> d(n, vector<ll>(n, 0));
  rep(i, n) rep(j, n) cin >> d[i][j];
  vector<vector<ll>> sum(n+1, vector<ll>(n+1, 0));
  rep(i, n) rep(j, n) sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + d[i][j];
  vector<ll> max_area(n * n + 1, 0);
  for (int x1 = 0; x1 < n; x1++){
    for (int x2 = x1 + 1; x2 <= n; x2++){
      for (int y1 = 0; y1 < n; y1++){
        for (int y2 = y1 + 1; y2 <= n; y2++){
          ll area = (x2 - x1) * (y2 - y1);
          ll num = sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1];
          chmax(max_area[area], num);
        }
      }
    }
  }
  for (int i = 0; i < n * n; i++)chmax(max_area[i+1], max_area[i]);
  int q;
  cin >> q;
  rep(i, q){
    ll p;
    cin >> p;
    cout << max_area[p] << endl;
  }
}