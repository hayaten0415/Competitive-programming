#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using LP = pair<long double, long double>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int n, k;
  cin >> n >> k;
  vector<long double> w(n), p(n);
  rep(i, n){
    cin >> w[i] >> p[i];
    p[i] /= (long double)100;
  }
  auto calc = [&](long double x) {
    vector<long double> v;
    rep(i, n) v.emplace_back((p[i] - x) * w[i]);
    sort(v.rbegin(), v.rend());
    long double sum = 0.0;
    rep(i, k) sum += v[i];
    return sum >= 0.0;
  };
  long double left = -1.0;
  long double right = 1.01;
  rep(i, 1000){
    long double mid = (left + right) * 0.5;
    if(calc(mid))left = mid;
    else right = mid;
  }
  left *= (long double)100;
  cout << fixed << setprecision(10) << left << endl;
}