#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<long double> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];
  long double mx = 0;
  rep(i, n){
    for(int j = i+1; j < n; j++){ 
      mx = max(mx, pow(x[j] - x[i], 2) + pow(y[j] - y[i], 2));
    }
  }
  long double ans = sqrt(mx);
  cout << fixed << setprecision(15) << ans << endl;
}