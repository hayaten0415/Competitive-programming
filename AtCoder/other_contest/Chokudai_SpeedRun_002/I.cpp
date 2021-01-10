#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<long long, long long>;
using PP = pair<long long, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};


int main() {
  int n;
  cin >> n;
  vector<ll> A(n), B(n);
  rep(i, n) cin >> A[i] >> B[i];
  vector<PP> ans(n);
  rep(i, n){
    ans[i] = PP(A[i] * B[i], i);
  }
  sort(ALL(ans), greater{});
  if(n == 1){
    cout << 1 << endl;
    return 0;
  }
  int k = ans[0].second;
  bool ok = true;
  rep(i, n){
    if(i == k)continue;
    ll d = (A[k] + B[i] - 1) / B[i];
    ll c = (A[i] + B[k] - 1) / B[k];
    if(c >= d)ok = false;
  }
  if(ok){
    cout << k + 1<< endl;
  }else{
    cout << -1 << endl;
  }
}