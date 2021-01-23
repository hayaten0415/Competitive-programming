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
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  ll ans = 0;
  if(A[0] != 0){
    cout << -1 << endl;
    return 0;
  }
  rep(i, n){
    if(A[i]> 0)ans++;
  }
  bool ok = true;
  rep(i, n-1){
    if(A[i+1] - A[i] > 1)ok = false;
    if(A[i+1] <= A[i] && A[i] != 0 && A[i+1] != 0)ans += (A[i+1] -1);
  }
  if(!ok){
    cout << -1 << endl;
  }else{
    cout << ans << endl;
  }
}