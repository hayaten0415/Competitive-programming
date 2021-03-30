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
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

vector<pair<ll,ll>> prime_factorize(ll n) {
  vector<pair<ll, ll>> res;
  for (long long a = 2; a * a <= n; a++){
    if(n % a != 0) continue;
    ll ex = 0; //指数
    while(n % a == 0){
      ex++;
      n /= a;
    }
    res.push_back(make_pair(a, ex));
  }
  if(n != 1){
    res.push_back(make_pair(n, 1));
  }
  return res;
}

void solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> prime = prime_factorize(n);
  ll k = 0;
  ll num = 0;
  for(auto d : prime){
    if(chmax(k, d.second)){
      num = d.first;
    }
  }
  cout << k << endl;
  rep(i, k-1){
    cout << num << " ";
    n /= num;
  }
  cout << n << endl;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
  solve();
}