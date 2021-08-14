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

int main() {
  string s;
  int n;
  cin >> n >> s;
  vector<ll> maru, batu;
  rep(i, n){
    if(s[i] == 'o')maru.pb(i);
    else batu.pb(i);
  }
  ll ans = 0;
  rep(i, n-1){
    if(s[i] == 'o'){
      if(batu.size() == 0)continue;
      ll d = *upper_bound(ALL(batu), i);
      if(d < i)continue;
      ans += (ll)n - d;
    }else{
      if(maru.size() == 0)continue;
      ll d = *upper_bound(ALL(maru), i);
      if(d < i)continue;
      ans += (ll)n - d;
    }
  }
  cout << ans << endl;
}