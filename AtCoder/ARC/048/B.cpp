#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int n;
  cin >> n;
  vector<vector<int>> ans(n, vector<int>(3));
  vector<vector<int>> rate_set(100000, vector<int>(3));
  vector<int> R(n), H(n), rate(n);
  rep(i, n){
    cin >> R[i] >> H[i];
    R[i]--, H[i]--;
    rate_set[R[i]][H[i]]++;
    rate[i] = R[i];
  }
  sort(ALL(rate));
  rep(i, n){
    int k = upper_bound(ALL(rate), R[i]) - rate.begin();
    int m = lower_bound(ALL(rate), R[i]) - rate.begin();
    ans[i][1] += n - k;
    ans[i][0] += m;
    if(H[i] == 0){
      ans[i][0] += rate_set[R[i]][1];
      ans[i][1] += rate_set[R[i]][2];
      ans[i][2] += rate_set[R[i]][0] -1;
    }else if(H[i] == 1){
      ans[i][0] += rate_set[R[i]][2];
      ans[i][1] += rate_set[R[i]][0];
      ans[i][2] += rate_set[R[i]][1] - 1;
    }else{
      ans[i][0] += rate_set[R[i]][0];
      ans[i][1] += rate_set[R[i]][1];
      ans[i][2] += rate_set[R[i]][2] - 1;
    }
    rep(j, 3){
      cout << ans[i][j] << (j == 2 ? "\n" : " ");
    }
  }
}