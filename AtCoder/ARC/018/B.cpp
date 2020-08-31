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
  vector<ll> X(n), Y(n);
  rep(i, n){
    cin >> X[i] >> Y[i];
  }
  int ans =0;
  for (int i = 0; i < n - 2; i++){
    for (int j = i + 1; j < n - 1; j++){
      for (int k = j + 1; k < n; k++){
        ll x1 = X[j] -X[i];
        ll x2 = X[k] - X[i];
        ll y1 = Y[j] - Y[i];
        ll y2 = Y[k] - Y[i];
        ll area = abs(x1 * y2 - x2 * y1);
        if(area % 2 == 0 && area > 0)ans++;
      }
    }
  }
  cout << ans << endl;
}