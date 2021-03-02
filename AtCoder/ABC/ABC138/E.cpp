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
const ll INF = (1LL << 60);

int main() {
  string s, t;
  cin >> s >> t;
  ll n = s.size();
  ll m = t.size();
  vector<vector<ll>> alpha(26);
  vector<int> S(26, 0), T(26, 0);
  rep(i, n){
    int c = s[i] - 'a';
    S[c]++;
    alpha[c].emplace_back(i);
  }
  rep(i, m){
    int c = t[i] - 'a';
    T[c]++;
  }
  bool ng = false;
  rep(i, 26){
    if(S[i] == 0 && T[i] > 0)ng = true;
  }
  if(ng){
    cout << -1 << endl;
    return 0;
  }
  ll ans = 0;
  ll loop = 0;
  ll now = -2;
  rep(i, m){
    ll a = t[i] - 'a';
    ll k = upper_bound(ALL(alpha[a]), now) - alpha[a].begin();
    ll d = INF;
    if(k < alpha[a].size()){
      d = alpha[a][k];
    }else{
      d = alpha[a][0];
    }
    if(d <= now){
      loop++;
      d = alpha[a][0];
    }
    now = d;
    ans = (ll)loop * n + now + 1;
  }
  cout << ans << endl;
}