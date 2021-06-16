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

using Mat = vector<vector<ll>>;

Mat operator*(Mat a, Mat b){
    int n = a.size();
    int l = b.size();
    int m = b[0].size();
    Mat ans(n, vector<ll>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < l; j++)
            for (int k = 0; k < m; k++)
                ans[i][k] += a[i][j] * b[j][k];
    return ans;
}
vector<Mat> points, mats;
int main() {
  int n, m;
  cin >> n;
  vector<ll> X(n), Y(n);
  rep(i, n){
    ll x, y;
    cin >> x >> y;
    points.push_back({{x}, {y}, {1}});
  }
  mats.pb({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});
  cin >> m;
  rep(i, m){
    int t;
    cin >> t;
    if(t== 1){
      mats.pb(Mat{{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}} * mats.back());
    }else if(t == 2){
      mats.pb(Mat{{0, -1, 0}, {1, 0, 0}, {0, 0, 1}} * mats.back());
    }else if(t == 3){
      int p;
      cin >> p;
      mats.pb(Mat{{-1, 0, 2 * p}, {0, 1, 0}, {0, 0, 1}} * mats.back());
    }else{
      int p;
      cin >> p;
      mats.pb(Mat{{1, 0, 0}, {0, -1, 2 * p}, {0, 0, 1}} * mats.back());
    }
  }
  int q;
  cin >> q;
  rep(i, q){
    int a, b;
    cin >> a >> b;
    b--;
    Mat ans = mats[a] * points[b];
    cout << ans[0][0] << " " << ans[1][0] << endl;
  }
}