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
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
  int n, p;
  ll k;
  cin >> n >> k >> p;
  vector<ll> A(n), B(n);
  vector<ll> cn_amari(2 * p);
  rep(i, n) cin >> A[i];
  rep(i, n){
    cin >> B[i];
    cn_amari[B[i]]++;
  }
  rep(i, p){
    cn_amari[p + i] = cn_amari[i];
  }
  vector<ll> cn_amari_sum(2 * p + 1);
  rep(i, 2* p){
    cn_amari_sum[i + 1] = cn_amari_sum[i] + cn_amari[i];
  }
  auto ok = [&](int d){
    ll cn = 0;
    rep(i, n){
      int start = p - A[i];
      int end = p + d - A[i];
      end++;
      cn += (cn_amari_sum[end] - cn_amari_sum[start]);
    }
    return cn >= k;
  };

  int left = -1, right = p-1;
  while(right - left > 1){
    int mid = (left + right) / 2;
    if(ok(mid)){
      right = mid;
    }else{
      left = mid;
    }
  }
  cout << right << endl;
}