#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define fi first
#define se second
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
using namespace std;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
template <typename T>
const auto INF = numeric_limits<T>::max() / 2;
vector<ll> one;
vector<ll> two;
void solve() {
  ll n;
  int k;
  cin >> n >> k;
  if(k == 1){
    cout << *lower_bound(ALL(one), n) << endl;
  }else{
    cout << *lower_bound(ALL(two), n) << endl;
  }
  
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  rep(i, 10){
    if(i == 0)continue;
    ll d = i;
    rep(j, 10){
      one.pb(d);
      two.pb(d);
      d = d * 10 + i;
    }
  }
  rep(i, 10) for (int j = i + 1; j < 10; j++)for(int c = 2; c <= 10; c++){
    rep(bit, 1<< c){
      ll d = 0;
      bool ok = true;
      rep(s, c){
        d *= 10;
        if(bit & (1 << s)){
          d += i;
        }else{
          d += j;
        }
        if(s == 0 && d== 0){
          ok = false;
          break;
        }
      }
      if(ok)two.pb(d);
    }
  }
  sort(ALL(one));
  sort(ALL(two));
  two.erase(unique(two.begin(), two.end()), two.end());
  while(t--) solve();
}