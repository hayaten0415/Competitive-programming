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
  ll q, h, s, d, n;
  cin >> q >> h >> s >> d >> n;
  ll one = min(h * 2, min(s, min(4 * q, 2 * q + h)));
  ll two = min(d, one * 2);
  ll two_count = n / 2;
  ll one_count = n % 2;
  cout << two_count * two + one_count * one << endl;
}