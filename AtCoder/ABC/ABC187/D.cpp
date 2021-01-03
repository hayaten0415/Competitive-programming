#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
using namespace std;
using P = pair<ll, ll>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

bool judge(P x, P y){
  return 2 * x.first + x.second > 2 * y.first + y.second;
}

int main() {
  int n;
  cin >> n;
  vector<P> AB(n), sum(n + 1, {0LL, 0LL});
  rep(i, n) {
    ll a, b;
    cin >> a >> b;
    AB[i] = {a, b};
  }
  sort(ALL(AB), judge);
  rep(i, n){
    sum[i + 1] = P(AB[i].first + AB[i].second + sum[i].first, AB[i].first + sum[i].second);
  }
  int mn = n;
  for (int i = 1; i <= n; i++){
    ll num1 = sum[i].first;
    ll num2 = sum[n].second - sum[i].second;
    if(num1 > num2){
      cout << i << endl;
      return 0;
    }
  }
  cout << mn << endl;
}