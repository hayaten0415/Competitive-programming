#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
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
string s;
vector<vector<int>> dp;
int rec(int l, int r) { // メモ化再帰
    if ((r - l + 1) <= 2) return 0;
    int &ret = dp[l][r]; // 更新の対象についての参照を宣言
    if (ret != -1) return ret;  // 既に計算済みならその値を使う
    chmax(ret, max(rec(l + 1, r), rec(l, r-1)));
    for (int i = l; i < r; i++) {
        chmax(ret, rec(l, i) + rec(i+ 1, r));
    }
    int len = r - l + 1;
    if(len % 3 == 0){
      for (int j = l + 1; j <= r - 1; j += 3) {
				if (s[l] == 'i' && s[j] == 'w' && s[r] == 'i') {
					int ledp = rec(l + 1, j - 1);
					int lelen = j - l - 1;
					int ridp = rec(j + 1, r - 1);
					int rilen = r - j - 1;
					if (ledp == lelen / 3 && ridp == rilen / 3) {
						ret = len / 3;
					}
				}
			}
    }
    return ret;
}

int main() {
  cin >> s;
  int n = s.size();
  dp.assign(n + 2, vector<int>(n + 2, -1));
  cout << rec(0, n-1) << endl;
}