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


void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  vector<PL> cn(n);
  rep(i, n){
    int d;
    cin >> A[i]>> d;
    A[i]--;
    cn[A[i]].first++;
    if(d == 1)cn[A[i]].second++;
  }
  vector<vector<ll>> cn1(n + 1);
  rep(i, n){
    cn1[cn[i].first].eb(cn[i].second);
  }
  priority_queue<ll> pq;
  ll ans1 = 0;
  ll ans2 = 0;
  rrep(i, n+1){
    for(ll x : cn1[i])pq.push(x);
    if(!pq.empty()){
      ans1 += i;
      ans2 += min(pq.top(), i);
      pq.pop();
    }
  }
  cout << ans1 << " " << ans2 << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}