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

ll gcd(ll a, ll b) {
  ll smaller = min(a, b);
  ll bigger = max(a, b);
  ll surplus = bigger % smaller;
  if (surplus == 0) return smaller;
  surplus = gcd(smaller, surplus);
  return surplus;
}


int main() {
  int n;
  cin >> n;
  vector<int> num(1001, 0);
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  for (int i = 2; i <= 1000; i++){
    rep(j, n){
      if(i > A[j])continue;
      if(A[j] % i == 0)num[i]++;
    }
  }
  int cn = 0;
  int ans = 1;
  rep(i, 1001){
    if(chmax(cn, num[i]))ans = i;
  }
  cout << ans << endl;
}