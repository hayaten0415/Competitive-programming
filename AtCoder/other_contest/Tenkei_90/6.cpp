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

int nex[100005][26];

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  for (int i = 0; i < 26; i++) nex[n][i] = n;
  for (int i = n - 1; i >= 0;i--){
    rep(j,26){
      if((int)(s[i] - 'a') == j){
        nex[i][j] = i;
      }else{
        nex[i][j] = nex[i+1][j];
      }
    }
  }

  string ans = "";
  int current = 0;
  for (int i = 1; i <= k; i++){
    rep(j, 26){
      int nexpo = nex[current][j];
      int length = (int)(n - nexpo - 1) + i;
      if (length >= k) {
				ans += (char)('a' + j);
				current = nexpo + 1;
				break;
			}
    }
  }
  cout << ans << endl;
}