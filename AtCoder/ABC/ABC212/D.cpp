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
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
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
const ll INF = (1LL <<60);

using S = ll;
using F = ll;
S op(S a, S b) { return std::min(a, b); }
S e() { return INF;}
S mapping(F f, S x) { return x + f; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }
ll target;
bool f(int v){
  return (v != target);
}

int main() {
  int q;
  cin >> q;
  ll plus = 0;
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  vector<ll> ans;
  rep(i, q){
    int t;
    cin >> t;
    if(t == 1){
      ll d;
      cin >> d;
      pq.push(d-plus);
    }else if(t == 2){
      ll b;
      cin >> b;
      plus += b;
    }else{
      ll x = pq.top();
      ans.pb(x + plus);
      pq.pop();
    }
  }
  for(auto d : ans){
    cout << d << endl;
  }
}