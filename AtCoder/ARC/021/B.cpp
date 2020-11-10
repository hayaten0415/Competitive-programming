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
  vector<int> A(n), B(n);
  rep(i, n) cin >> B[i];
  A[0] = 0;
  rep(i, n-1){
    A[i + 1] = B[i] ^ A[i];
  }
  if(B[n-1] != (A[0] ^ A[n-1])){
    cout << -1 << endl;
  }else{
    rep(i, n){
      cout << A[i] << endl;
    }
  }
}