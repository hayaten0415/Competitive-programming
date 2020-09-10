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
  int w, h, n;
  cin >> w >> h >> n;
  vector<int> x(n), y(n);
  int ans = 0;
  rep(i, n) cin >> x[i] >> y[i];
  rep(i, n-1){
    int num1 = x[i + 1] - x[i];
    int num2 = y[i + 1] - y[i];
    if(num1 * num2 < 0){
      ans += abs(num1) + abs(num2);
    }else{
      ans += max(abs(num1), abs(num2));
    }
  }
  cout << ans << endl;
}