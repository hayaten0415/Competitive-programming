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
const int INF = (1 << 30);

int dfs(int m, const string s, int f, int cn){
  int num = INF;
  if(m == 1){
    if(s[0] - 'a' != f)return cn + 1;
    else return cn;
  }
  int num1 = cn;
  int num2 = cn;
  string s1 = s.substr(0, m / 2);
  string s2 = s.substr(m / 2 , m);
  rep(i, m / 2){
    if(s1[i] - 'a' != f)num1++;
  }
  rep(i, m / 2){
    if(s2[i] - 'a' != f)num2++;
  }
  chmin(num, dfs(m / 2, s2, f + 1, num1));
  chmin(num, dfs(m / 2, s1, f + 1, num2));
  return num;
}

void solve() {
  string s;
  int n;
  cin >> n >> s;
  int ans = dfs(n, s, 0, 0);
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}