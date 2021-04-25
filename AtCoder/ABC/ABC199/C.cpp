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
  string s;
  cin >> s;
  int q;
  cin >> q;
  int N = n * 2;
  vector<char> ans_a(n), ans_b(n);
  rep(i, n) ans_a[i] = s[i];
  rep(i, n) ans_b[i] = s[i + n];
  rep(i, q){
    int t, a, b;
    cin >> t >> a >> b;
    a--, b--;
    if(t == 1){
      if(a <n && b < n){
        swap(ans_a[a], ans_a[b]);
      }else if(a <n && b >= n){
        b -= n;
        swap(ans_a[a], ans_b[b]);
      }else{
        a -= n;
        b -= n;
        swap(ans_b[a], ans_b[b]);
      }
    }else{
      swap(ans_a, ans_b);
    }
  }
  rep(i, n){
    cout << ans_a[i];
  }
  rep(i, n){
    cout << ans_b[i];
  }
  cout << endl;
}