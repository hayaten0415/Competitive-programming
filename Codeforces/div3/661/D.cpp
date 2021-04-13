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
  string s;
  cin >> s;
  stack<ll> zero, one;
  vector<ll> ans(n);
  ll num = 0;
  rep(i, n){
    if(s[i] == '0'){
      if(zero.size()){
        auto idx = zero.top();
        zero.pop();
        ans[i] = idx;
        one.push(idx);
      }else{
        num++;
        ans[i] = num;
        one.push(num);
      }
    }
    if(s[i] == '1'){
      if(one.size()){
        auto idx = one.top();
        one.pop();
        ans[i] = idx;
        zero.push(idx);
      }else{
        num++;
        ans[i] = num;
        zero.push(num);
      }
    }
  }
  cout << num << endl;
  rep(i, n){
    cout << ans[i] << (i == n - 1 ? "\n" : " ");
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}