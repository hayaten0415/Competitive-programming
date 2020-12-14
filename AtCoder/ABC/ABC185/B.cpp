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
  int m;
  ll n, t;
  cin >> n >> m >> t;
  vector<int> A(m), B(m);
  rep(i, m){
    cin >> A[i] >> B[i];
  }
  ll tmp = n - A[0];
  if(tmp <= 0){
    cout << "No" << endl;
    return 0;
  }
  bool ok = true;
  rep(i, m){
    tmp += B[i] - A[i];
    tmp = min(tmp, n);
    if(i < m-1){
      tmp -= A[i + 1] - B[i];
    }else{
      tmp -= t - B[i];
    }
    if(tmp <= 0){
      ok = false;
    }
  }
  if(ok){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}