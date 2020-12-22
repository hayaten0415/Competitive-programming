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


template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n = 0) : n(n), d(n + 1) {}
  void add(int i, T x) {
    for (i++; i <= n; i += i & -i){
      d[i] += x;
    }
  }
  
  T sum(int i) {
    T num = 0;
    for (i++; i; i -= i & -i){
      num += d[i];
    }
    return num;
  }
  /* [l, r), a and b are 1-indexed */
  T sum(int l, int r) {
    return sum(r - 1) - sum(l - 1);
  }

  int get(long long k) {
      ++k;
      int res = 0;
      int N = 1; while (N < (int)d.size()) N *= 2;
      for (int i = N / 2; i > 0; i /= 2) {
          if (res + i < (int)d.size() && d[res + i] < k) {
              k = k - d[res + i];
              res = res + i;
          }
      }
      return res + 1;
  }
};


int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, n) cin >> v[i];
  ll ans = 0;
  BIT<int> b(n);
  rep(i, n){
    ans += i - b.sum(v[i]-1);
    b.add(v[i] - 1, 1);
  }
  cout << ans << endl;
}