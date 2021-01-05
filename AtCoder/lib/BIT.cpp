#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

//0-indexed
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
