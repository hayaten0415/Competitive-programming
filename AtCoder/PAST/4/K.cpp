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
const ll mod = 1000000000;

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
  /* [l, r), a and b are 0-indexed */
  T sum(int l, int r) {
    return sum(r) - sum(l);
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
  int k;
  cin >> k;
  vector<vector<ll>> cn(k, vector<ll>(20, 0));
  vector<ll> tentou(k);
  rep(s, k){
    int n;
    cin >> n;
    BIT<ll> b(20);
    rep(i, n){
      int a;
      cin >> a;
      a--;
      cn[s][a]++;
      tentou[s] += i - b.sum(a);
      b.add(a, 1);
    }
  }
  int q;
  cin >> q;
  ll ans = 0;
  BIT<ll> b(20);
  rep(i, q){
    int d;
    cin >> d;
    d--;
    ans += tentou[d];
    ans %= mod;
    rep(j,20){
      if(cn[d][j] == 0)continue;
      ans += b.sum(j, 19) * cn[d][j];
      ans %= mod;
      b.add(j, cn[d][j]);
    }
  }
  cout << ans << endl;
}