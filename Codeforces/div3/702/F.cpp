#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

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




void solve(){
  int n;
  cin >> n;
  vector<int> A(n);
  map<int, int> mp;
  vector<int> ans;
  rep(i, n){
    cin >> A[i];
    mp[A[i]]++;
  }
  for(auto p : mp){
    ans.emplace_back(p.second);
  }
  sort(ALL(ans));
  int d = ans.size();
  BIT<int> bt(d+1);
  rep(i, d){
    bt.add(i+1, ans[i]);
  }
  int limit = ans[d - 1];
  int res = n;
  //cout << bt.sum(0, d) << endl;
  rep(i, limit + 1){
    int s = lower_bound(ALL(ans), i) - ans.begin();
    int f = upper_bound(ALL(ans), i) - ans.begin();
    chmin(res, bt.sum(0, s) + bt.sum(f, d) - (d - f) * i);
  }
  cout << res << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}