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

struct Doubling{
  vector<vector<ll>> next, sum;
  Doubling(vector<ll> in, int log){
    next.resize(log);
    rep(i, log) next[i].resize(in.size());
    rep(i, in.size()) next[0][i] = in[i];
    for(int i=1;i<log;i++) rep(j,in.size()) next[i][j]=next[i-1][next[i-1][j]];
    sum.resize(log);
    rep(i, log) sum[i].resize(in.size());
    rep(i, in.size()) sum[0][i] = i;
    for(int i=1;i<log;i++) rep(j,in.size()) sum[i][j]=sum[i-1][j] + sum[i-1][next[i-1][j]];
  }
  ll oppose(ll now, ll k){
    rep(i, next.size())if(k & (1ll << i)) now = next[i][now];
    return now;
  }
  ll doublesum(ll now, ll k){//Σ[i=0..k-1]
    ll res = 0;
    rep(i, next.size()){
      if (k & (1ll << i)){
        res += sum[i][now];
        now = next[i][now];
      }
    } 
    return res;
  }
};
//verify https://atcoder.jp/contests/abc167/tasks/abc167_d
//verify https://atcoder.jp/contests/abc179/tasks/abc179_e

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> A(n);
  rep(i, n){
    cin >> A[i];
    A[i]--;
  }
  Doubling db(A, 60);
  cout << db.oppose(0, k) + 1 << endl;
}