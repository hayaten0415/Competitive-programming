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
  pair<int, int> now = {0, 0};
  map<pair<int, int>, int> vis;
  int l = -1, r = n;
  vis[now] = 0;
  rep(i, n){
    if (s[i] == 'L') --now.first;
		if (s[i] == 'R') ++now.first;
		if (s[i] == 'U') ++now.second;
		if (s[i] == 'D') --now.second;
    if(vis.count(now)){
      if (i - vis[now] + 1 < r - l + 1) {
					l = vis[now];
					r = i;
			}
    }
    vis[now] = i + 1;
  }
  if (l == -1) {
		cout << -1 << endl;
	} else {
		cout << l + 1 << " " << r + 1 << endl;
	}
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}