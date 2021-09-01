#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
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
using mint = modint1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> T(n), A(n);
  vector<P> mnT(n), mnA(n);
  rep(i, n) cin >> T[i];
  rep(i, n) cin >> A[i];
  mnT[0] = {T[0], T[0]};
  mnA[n-1] = {A[n-1], A[n-1]};
  rep(i, n-1){
    if(T[i] < T[i+1]){
      mnT[i + 1] = {T[i + 1], T[i + 1]};
    }else{
      mnT[i+1] = {1, T[i+1]};
    }
  }
  rrep(i, n-1){
    if(A[i] > A[i+1]){
      mnA[i] = {A[i], A[i]};
    }else{
      mnA[i] = {1, A[i]};
    }
  }
  mint ans = 1;
  rep(i, n){
    int l1 = mnT[i].fi;
    int r1 = mnT[i].se;
    int l2 = mnA[i].fi;
    int r2 = mnA[i].se;
    ans *= max(0, min(r1, r2) - max(l1, l2) + 1);
  }
  cout << ans.val() << endl;
}