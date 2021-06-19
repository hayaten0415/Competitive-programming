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

using Mat = vector<vector<ll>>;
Mat mul(Mat &a, Mat &b){
  int n = a.size();
  int l = b.size();
  int m = b[0].size();
  Mat ans(n, vector<ll>(m, 0));
  for (int i = 0; i < n; i++)
      for (int j = 0; j < l; j++)
          for (int k = 0; k < m; k++)
            ans[i][k] ^= (a[i][j] & b[j][k]);
  return ans;
}

Mat matpow(Mat A, ll n){
  Mat B = Mat(A.size(), vector<ll>(A.size()));
  //&演算での単位行列はB[i][i] = 全てのビットが立っているもの(1LL << 60 -1)
  rep(i, A.size())B[i][i] = (1LL << 60)-1;
  while(n > 0){
    if(n & 1) B = mul(B, A);
    A = mul(A, A);
    n >>= 1;
  }
  return B;
}


int main() {
  ll k;
  ll m;
  cin >> k >> m;
  Mat A(k, vector<ll>(k));
  Mat a(k, vector<ll>(1));
  rrep(i, k){
    cin >> a[i][0];
  }
  rep(i, k){
    cin >> A[0][i];
  }
  rep(i, k - 1) A[i + 1][i] = (1LL << 60)-1;
  if(k >= m){
    cout << a[k- m][0] << endl;
    return 0;
  }
  A = matpow(A, m- k);
  Mat ans = mul(A, a);
  cout << ans[0][0] << endl;
}