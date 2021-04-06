#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
using namespace std;
using P = pair<int, int>;
using PL = pair<long long, long long>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

ll string_to_long(string s, int a){
  reverse(ALL(s));
  int n = s.size();
  ll ten = 1;
  ll res = 0;
  rep(i, a){
    ll k = s[i] - '0';
    res += k * ten;
    ten *= 10;
  }
  return res;
}


void solve() {
  string n;
  ll s;
  cin >> n >> s;
  int d = n.size();
  int sum = 0; 
  rep(i, d){
    sum += n[i] - '0';
  }
  if(sum <= s){
    cout << 0 << endl;
    return;
  }
  sum = 0;
  int a = -1;
  rep(i, d){
    sum += n[i] - '0';
    if(sum >= s){
      a = i;
      break;
    }
  }
  ll f = (ll)pow(10, d - a);
  ll rest = string_to_long(n, d- a);
  cout << f - rest << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}