#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

template <typename T>
map<T, int> compress(vector<T> &X) {
  vector<T> vals = X;
  int n = vals.size();
  map<T, int> mp;
  int cn = 0;
  rep(i, n){
    mp[X[i]] = 0;
  }
  for (auto &p : mp){
    p.second = cn;
    cn++;
  }
  return mp;
}

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  map<int, int> mp;
  rep(i, n){
    cin >> A[i];
    A[i]--;
  }
  mp = compress(A);
  dsu d(mp.size());
  rep(i, n){
    if(A[i] != A[n-1-i]){
      d.merge(mp[A[i]], mp[A[n - 1 - i]]);
    }
  }
  int ans = 0;
  for(auto s : d.groups()){
    ans += (s.size() - 1);
  }
  cout << ans << endl;
}