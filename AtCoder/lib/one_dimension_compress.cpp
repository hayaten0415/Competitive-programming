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
  rep(i, n) cin >> A[i];
  map<int, int> mp = compress(A);
  rep(i, n){
    cout << mp[A[i]] << endl;
  }
}