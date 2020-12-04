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
  ll n;
  cin >> n;
  ll left = 0;
  ll right = 2000000000;
  while (right - left > 1){
    ll mid = (right + left) / 2;
    ll sum = mid * (mid + 1) / 2;
    if (sum <= n+ 1)left = mid;
    else right = mid;
  }
  cout << n - left + 1 << endl;
}