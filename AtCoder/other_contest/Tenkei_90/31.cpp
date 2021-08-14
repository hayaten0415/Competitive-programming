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


int grundy[60][1700];

void init() {
  rep(i, 51){
    rep(j, 1501){
      int mex[1555];
      rep(k, 1555)mex[k] = 0;
      if(i >= 1){
        mex[grundy[i - 1][j + i]] = 1;
      }
      if(j >= 2){
        for (int k = 1; k <= (j / 2); k++){
          mex[grundy[i][j - k]] = 1;
        }
      }
      rep(k, 1555){
        if(mex[k] == 0){
          grundy[i][j] = k;
          break;
        }
      }
    }
  }
}
int main() {
  init();
  int n;
  cin >> n;
  vector<int> A(n), B(n);
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> B[i];
  int sum = 0;
  rep(i, n) sum ^= grundy[A[i]][B[i]];
  if(sum != 0){
    cout << "First"<< endl;
  }else{
    cout << "Second" << endl;
  }
}