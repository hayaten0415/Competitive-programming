#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  ll ans = 1000000000000000;
  vector<ll> A(n), B(n);
  rep(i, n) cin >> A[i] >> B[i];
  rep(i, n) {
    rep(j, n) {
      ll start = A[i];
      ll goal = B[j];
      ll num = 0;
      rep(k, n) {
        if(start <= A[k]){
          num += A[k] - start;
        }else if(start > A[k]){
          num += start - A[k];
        }
        num += B[k] - A[k];
        if(goal >= B[k]){
          num += goal - B[k];
        }else{
          num += B[k] - goal;
        }
      }
      ans = min(ans, num);
    }
  }
  cout << ans << endl;
}