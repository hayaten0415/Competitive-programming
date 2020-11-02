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
  vector<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];
  rep(i, n){
    rep(j, n){
      if(i == j)continue;
      rep(k, n){
        if(i == k)continue;
        if(j == k)continue;
        int x1 = x[i], x2 = x[j], x3 = x[k];
        int y1 = y[i], y2 = y[j], y3 = y[k];
        x2 -= x1, x3 -= x1;
        y2 -= y1, y3 -= y1;
        if(x2 * y3 == y2 * x3){
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
}