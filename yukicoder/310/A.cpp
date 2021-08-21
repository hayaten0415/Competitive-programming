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
  int n;
  cin >> n;
  vector<int> A(n), B(n);
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> B[i];
  vector<P> ans;
  int res = 0;
  rep(i, n){
    res += abs(A[i] - B[i]);
    if(A[i]>= B[i]){
      ans.pb({0, i});
    }else{
      ans.pb({1, i});
    }
  }
  sort(ALL(ans), [](P x, P y){
    if(x.first != y.first){
      return x.first < y.first;
    }else if(x.first == 0){
      return x.second < y.second;
    }else{
      return x.second > y.second;
    }
  });
  cout << res << endl;
  for (auto [a, b] : ans){
    if(a == 0){
      rep(i, abs(A[b] - B[b])){
        cout << b + 1 << " L" << endl;
      }
    }else{
      rep(i, abs(A[b] - B[b])){
        cout << b + 1 << " R" << endl;
      }
    }
  }
}