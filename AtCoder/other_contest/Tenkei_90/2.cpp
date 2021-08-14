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
  if(n % 2 == 1){
    cout << endl;
    return 0;
  }
  vector<string> ans;
  for (int bit = 0; bit < (1 << n); bit++){
    int d = popcount(bit);
    if(d != n / 2)continue;
    stack<int> left, right;
    string tmp = "";
    rep(i, n){
      if(bit & (1 <<i)){
        left.push(0);
        tmp +='(';
      }else{
        if(!left.empty()){
          left.pop();
          tmp += ')';
        }else{
          tmp += ')';
          right.push(0);
        }
      }
    }
    if(left.empty() & right.empty()){
      ans.pb(tmp);
    }
  }
  sort(ALL(ans));
  rep(i, ans.size()){
    cout << ans[i] << endl;
  }
}