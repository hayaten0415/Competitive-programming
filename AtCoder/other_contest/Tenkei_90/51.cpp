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
  int n, k;
  ll p;
  cin >> n >> k >> p;
  vector<ll> half1[40], half2[40];
  vector<ll> A_half1, A_half2;
  rep(i, n){
    ll a;
    cin >> a;
    if (i < n / 2){
      A_half1.pb(a);
    }else{
      A_half2.pb(a);
    }
  }
  int s = A_half1.size();
  int d = A_half2.size();
  rep(bit, (1 << s)){
    ll sum = 0;
    int f = popcount(bit);
    rep(i, s){
      if(bit &(1 << i))sum += A_half1[i];
    }
    half1[f].pb(sum);
  }
  rep(bit, (1 << d)){
    ll sum = 0;
    int f = popcount(bit);
    rep(i, d){
      if(bit &(1 << i))sum += A_half2[i];
    }
    half2[f].pb(sum);
  }
  ll ans = 0;
  rep(i, 40) sort(ALL(half2[i]));
  rep(i, k + 1){
    for(auto c : half1[i]){
      if(c > p)continue;
      int f = upper_bound(ALL(half2[k - i]), p - c) - half2[k - i].begin();
      ans += f;
    }
  }
  cout << ans << endl;
}