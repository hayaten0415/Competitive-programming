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
using namespace std;
using P = pair<int, int>;
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
  vector<ll> A(n), A_f(n), A_b(n);
  rep(i, n) cin >> A[i];
  ll num = 0;
  rep(i, n){
    A_f[i] = num ^ A[i];
    num = A_f[i];
  }
  num = 0;
  rrep(i, n){
    A_b[i] = num ^ A[i];
    num = A_b[i];
  }
  bool ok = false;
  rep(i, n){
    ll pre = A_f[i];
    for(int j = i + 1; j < n; j++){
      int num = A_f[j] ^ pre;
      if(num == A_f[i]){
        pre = A_f[j];
        if(j == n-1)ok = true;
      }
    }
    pre = 0;
    for(int j = n-1; j > i; j--){
      int num = A_b[j] ^ pre;
      if(num == A_f[i]){
        pre = A_b[j];
        if(j == i + 1){
          ok = true;
        }
      }
    }
  }
  rrep(i, n){
    ll pre = A_b[i];
    for(int j = i - 1; j >= 0; j--){
      int num = A_b[j] ^ pre;
      if(num == A_b[i]){
        pre = A_b[j];
        if(j == 0)ok = true;
      }
    }
    pre = 0;
    for(int j = 0; j < i; j++){
      int num = A_f[j] ^ pre;
      if(num == A_b[i]){
        pre = A_f[j];
        if(j == i-1)ok = true;
      }
    }
  }
  if(ok){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}