#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define i128 __int128_t
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  string x;
  ll m;
  cin >> x >> m;
  int n = x.size();
  int d = 0;
  if(x.size()==1){
    if(stoi(x)<=m) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
  }
  vector<int> v;
  rep(i, n){
    int k = x[i] - '0';
    v.emplace_back(k);
    chmax(d, k);
  }
  ll ok = d, ng = m + 1;
  while (ng - ok > 1){
    ll mid = (ok + ng) / 2;
    bool flag = true;
    i128 t = 0;
    for(auto e : v) {
      t = t * mid + e;
      if(t > m) flag = false;
    }
    (flag ? ok : ng) = mid;
  }
  cout << ok - d << endl;
}