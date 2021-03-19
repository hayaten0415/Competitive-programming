#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

ll dp[2010];

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> category[10];
  rep(i, n){
    ll a;
    int b;
    cin >> a >> b;
    b--;
    category[b].eb(a);
  }
  rep(i, 10){
    sort(ALL(category[i]), greater{});
    for (int d = 1; d < category[i].size(); d++){
      category[i][d] += category[i][d - 1] + d * 2;
    }
  }
  rep(j, 10){
    for(int i = k; i>= 0; i--){
      rep(s, category[j].size()){
        if(i + s + 1 <= k){
          chmax(dp[i + s + 1], dp[i] + category[j][s]);
        }
      }
    }
  }
  cout << dp[k] << endl;
}