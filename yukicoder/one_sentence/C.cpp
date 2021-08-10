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
template <typename T>
const auto INF = numeric_limits<T>::max();

int main() {
  int n;
  cin >> n;
  vector<ll> A(n), B(n), sum_A(n + 1, 0), sum_B(n + 1, 0);
  vector<ll> CA(2 * n), CB(2 * n);
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> B[i];
  rep(i, n){
    sum_A[i + 1] = sum_A[i] + A[i];
    sum_B[i + 1] = sum_B[i] + B[i];
  }
  CA[1] = sum_A[1];
  CB[1] = sum_B[1];
  for (int i = 2; i < 2 *n; i++){
    if(i <= n){
      CA[i] = CA[i - 1] + sum_A[i];
      CB[i] = CB[i - 1] + sum_B[i];
    }else{
      CA[i] = CA[i - 1] + sum_A[n] - sum_A[i - n] - n * A[i - n - 1];
      CB[i] = CB[i - 1] + sum_B[n] - sum_B[i - n] - n * B[i - n - 1];
    }
  }
  rep(i, 2 * n){
    cout << CA[i] + CB[i] << (i == 2 * n -1 ? "\n" : " ");
  }
}