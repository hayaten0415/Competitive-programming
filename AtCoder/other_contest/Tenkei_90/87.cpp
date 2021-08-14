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
using PL = pair<long long, long long>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll INF = (1LL << 60);
vector<vector<ll>> dist(40, vector<ll>(40));

int main() {
  int k;
  ll p;
  cin >> n >> p >> k;
  rep(i, n)rep(j, n){
    cin >> dist[i][j];
  }
  auto ok1 = [&](ll d, int c){
    vector<vector<ll>> dist_tmp = dist;
    rep(i, n)rep(j, n)if(dist_tmp[i][j] == -1)dist_tmp[i][j] = d;
    rep(i, n) rep(j, n) rep(k, n) chmin(dist_tmp[j][k], dist_tmp[j][i] + dist_tmp[i][k]);
    int cn = 0;
    rep(i, n) for (int j = i + 1; j < n; j++)if(dist_tmp[i][j] <= p)cn++;
    return cn > c;
  };
  auto ok2 = [&](ll d, int c){
    vector<vector<ll>> dist_tmp = dist;
    rep(i, n)rep(j, n)if(dist_tmp[i][j] == -1)dist_tmp[i][j] = d;
    rep(i, n) rep(j, n) rep(k, n) chmin(dist_tmp[j][k], dist_tmp[j][i] + dist_tmp[i][k]);
    int cn = 0;
    rep(i, n) for (int j = i + 1; j < n; j++)if(dist_tmp[i][j] <= p)cn++;
    return cn >= c;
  };
  ll left = 0, right = (ll)INF;
  while(right - left > 1){
    ll mid = (left + right) / 2;
    if(ok1(mid, k)){
      left = mid;
    }else{
      right = mid;
    }
  }
  ll rest_left = right;
  left = 0, right = (ll)INF;
  while(right - left > 1){
    ll mid = (left + right) / 2;
    if(ok2(mid, k)){
      left = mid;
    }else{
      right = mid;
    }
  }
  if(rest_left == INF){
    cout << 0 << endl;
    return 0;
  }
  if(right == INF){
    cout << "Infinity" << endl;
  }else{
    cout << right - rest_left << endl;
  }
}