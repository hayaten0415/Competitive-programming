#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
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

using Mat = vector<vector<ll>>;
ll mod;
Mat mul(Mat &a, Mat &b){
  int n = a.size();
  int l = b.size();
  int m = b[0].size();
  Mat ans(n, vector<ll>(m, 0));
  for (int i = 0; i < n; i++)
      for (int j = 0; j < l; j++)
          for (int k = 0; k < m; k++)
            ans[i][k] += (a[i][j] * b[j][k]) % 10LL, ans[i][k] %= 10LL;
  return ans;
}

Mat matpow(Mat A, ll n){
  //演算に応じた単位行列を定義する
  Mat B = Mat(A.size(), vector<ll>(A.size()));
  rep(i, A.size()) B[i][i] = 1;
  while(n > 0){
    if(n & 1) B = mul(B, A);
    A = mul(A, A);
    n >>= 1;
  }
  return B;
}


//verify https://yukicoder.me/problems/no/526
int main() {
  Mat A(3, vector<ll>(3));
  Mat B(3, vector<ll>(1));
  rrep(i, 3){
    cin >> B[i][0];
    B[i][0] %= 10;
  }
  ll k;
  cin >> k;
  for (int i = 1; i < 3; i++)A[i][i-1] = 1;
  rep(i, 3)A[0][i] = 1;
  if(3 >= k){
    cout << B[3- k][0] << endl;
    return 0;
  }
  A = matpow(A, k - 3);
  A = mul(A, B);
  cout << A[0][0] << endl;
}