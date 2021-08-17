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
const auto INF = numeric_limits<T>::max();


void solve() {
  vector<ll> A(3);
  rep(i, 3) cin >> A[i];
  sort(ALL(A));
  ll ans = 0;
  do{
    ll Bob = A[0];
    ll Alice = A[1];
    ll tmp = A[2];
    if(Bob < Alice){
      ll d = min(tmp, Alice - Bob);
      tmp -= d;
      Bob += d;
      chmax(ans, Bob + (tmp / 2LL));
    }
    if(Alice < Bob){
      ll d = min(tmp, Bob - Alice);
      tmp -= d;
      Alice += d;
      chmax(ans, Alice + (tmp / 2LL));
    }
    if(Alice == Bob){
      chmax(ans, Alice + (tmp / 2LL));
    }
  }while(next_permutation(ALL(A))); 
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}