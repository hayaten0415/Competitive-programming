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
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  int ans = 0;
  if(a <= 0){
    ans += abs(a) * c;
    ans += d;
    ans += e;
  }
  if(b < 2){
    cout << ans << endl;
    return 0;
  }
  if(b >= 2 && a <= 0){
    ans += (b - 1) * e;
    cout << ans << endl;
    return 0;
  }
  cout << (b - a) * e << endl;
}