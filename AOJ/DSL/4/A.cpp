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
#define popcountll(bit) __builtin_popcountll(bit)
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

/* compress
    (X1,Y1),(X2,Y2)という二点で表されるもの（長方形や直線など）について、行か列の片方（X1とX2 or Y1とY2）を座標圧縮する（副作用）
    返り値: ソートされ重複要素を除いた値
    計算量: O(n log n)
*/
template <typename T>
vector<T> compress(vector<T> &C1, vector<T> &C2) {
    vector<T> vals;
    int N = (int)C1.size();
    for (int i = 0; i < N; i++) {
        for (T d = 0; d <= 1; d++) {  // for (T d = 0; d <= 0; d++) でも良い
            T tc1 = C1[i] + d;
            T tc2 = C2[i] + d;
            vals.push_back(tc1);
            vals.push_back(tc2);
        }
    }
    // ソート
    sort(vals.begin(), vals.end());
    // 隣り合う重複を削除(unique), 末端のゴミを削除(erase)
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int i = 0; i < N; i++) {
        C1[i] = lower_bound(vals.begin(), vals.end(), C1[i]) - vals.begin();
        C2[i] = lower_bound(vals.begin(), vals.end(), C2[i]) - vals.begin();
    }
    return vals;
}


void solve() {
  int n;
  cin >> n;
  vector<long long> X1(n), Y1(n), X2(n), Y2(n);
  rep(i, n){
    cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
  }
  // 座標圧縮
  vector<long long> X = compress(X1, X2);
  vector<long long> Y = compress(Y1, Y2);
  int w = (int)X.size();
  int h = (int)Y.size();
  vector<vector<int>> G(w, vector<int>(h));
  rep(i, n){
    G[X1[i]][Y1[i]]++;
    G[X2[i]][Y2[i]]++;
    G[X1[i]][Y2[i]]--;
    G[X2[i]][Y1[i]]--;
  }
  for (int x = 1; x < w; x++) {
    for (int y = 0; y < h; y++) {
      G[x][y] += G[x - 1][y];
    }
  }
  for (int x = 0; x < w; x++) {
    for (int y = 1; y < h; y++) {
      G[x][y] += G[x][y - 1];
    }
  }
  ll ans = 0;
  rep(i, w-1)rep(j, h-1){
    if(G[i][j] > 0){
      ans += (X[i + 1] - X[i]) * (Y[j + 1] - Y[j]);
    }
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t = 1;
  while(t--) solve();
}