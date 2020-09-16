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

//最小公倍数を求めるメソッド
ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}

int main() {
  ll n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  bool ok = true;
  if(s[0] != t[0]) ok = false;
  if(n ==m){
    if(s != t)ok = false;
  }
  if(gcd(n,m) > 1){
    int s_num = n / gcd(n, m);
    int t_num = m / gcd(n, m);
    int i = 0;
    int j = 0;
    while (i < n && j < m){
      if(s[i] != t[j]){
        ok = false;
        break;
      }
      i += s_num;
      j += t_num;
    }
  }
  if(ok){
    cout << lcm(n, m) << endl;
  }else{
    cout << -1 << endl;
  }
}