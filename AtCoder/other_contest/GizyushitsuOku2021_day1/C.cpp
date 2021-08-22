#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define fi first
#define se second
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
template <typename T>
const auto INF = numeric_limits<T>::max()/2;

int main() {
  ll n;
  cin >> n;
  vector<ll> A;
  ll num = 0;
  ll mid = -1;
  rep(i, 2 * n -1){
    ll a;
    cin >> a;
    if(a == -1){
      num++;
      continue;
    }
    if(i == 0){
      mid = a;
    }else{
      A.pb(a);
    }
  }
  sort(ALL(A));
  if(A.size() == 0){
    cout << "Yes" << endl;
    return 0;
  }
  ll c = lower_bound(ALL(A), mid) - A.begin();
  ll d = upper_bound(ALL(A), mid) - A.begin();
  ll ok = (d - c);
  ll left = abs(n - 1 - c);
  ll right = abs(n - 1 - ((ll)A.size() - d));
  ll ng = left + right;
  ng -= ok;
  ng -= num;
  if(ng > 0){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }
}