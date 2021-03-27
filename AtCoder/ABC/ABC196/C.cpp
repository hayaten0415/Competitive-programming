#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

ll string_to_long(string s){
  reverse(ALL(s));
  int n = s.size();
  ll ten = 1;
  ll res = 0;
  rep(i, n){
    ll k = s[i] - '0';
    res += k * ten;
    ten *= 10;
  }
  return res;
}

int main() {
  ll n;
  cin >> n;
  vector<ll> ans;
  for (int i = 1; i <= 1000000; i++){
    string tmp = to_string(i);
    string tmp2 = tmp;
    string res1 = tmp + tmp2;
    ll res2 = string_to_long(res1);
    ans.emplace_back(res2);
  }
  sort(ALL(ans));
  cout << upper_bound(ALL(ans), n) - ans.begin() << endl;
}