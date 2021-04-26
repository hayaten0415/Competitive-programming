#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
using namespace std;
using P = pair<int, int>;
using PP = pair<int, P>;
using PL = pair<long long, long long>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};


void solve() {
  int n;
  cin >> n;
  priority_queue<PP> pq;
  pq.push({n, {-0, -(n - 1)}});
  vector<int> A(n);
  rep(i, n){
    auto D = pq.top();
    auto [left, right] = D.second;
    left *= -1;
    right *= -1;
    int len = D.first;
    int mid;
    if(len % 2 == 0){
      A[(left + right -1) / 2] = i;
      mid = (left + right - 1) / 2;
    }else{
      A[(left + right) / 2] = i;
      mid = (left + right) / 2;
    }
    pq.pop();
    if(left < mid){
      pq.push({mid - left, {-left, -(mid - 1)}});
    }
    if(mid < right){
      pq.push({right - mid, {-(mid + 1), -(right)}});
    }
  }
  rep(i, n){
    cout << A[i] + 1 << (i == n - 1 ? "\n" : " ");
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}