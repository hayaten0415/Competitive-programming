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

int main() {
  int n;
  cin >> n;
  vector<ll> A(2 * n);
  vector<ll> sum_A(2 * n + 1);
  rep(i, n) cin >> A[i];
  ll sum = accumulate(ALL(A), 0LL);
  if(sum % 10 != 0){
    cout << "No" << endl;
    return 0;
  }
  rep(i, n){
    A[n + i] = A[i];
  }
  rep(i, 2 * n){
    sum_A[i + 1] = A[i] + sum_A[i];
  }
  auto cond = [&](int l,int r){
    return (sum_A[r] - sum_A[l] >= (sum / 10));
  };
  bool ok = false;
  rep(i, 2 * n){
    int left = 0, right = i + 1;
    while(right - left > 1){
      int mid = (left + right) / 2;
      if(cond(mid, i+1)){
        left = mid;
      }else{
        right = mid;
      }
    }
    if(sum_A[i + 1] - sum_A[left] == sum / 10)ok = true; 
  }
  if(ok){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}