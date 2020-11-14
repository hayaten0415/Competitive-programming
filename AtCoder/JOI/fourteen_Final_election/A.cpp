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
  int n, m;
  cin >> n >> m;
  vector<int> move(m);
  rep(i, m){
    cin >> move[i];
    move[i]--;
  }
  vector<ll> east_imos(n), west_imos(n), sum_imos(n);
  rep(i, m-1){
    if(move[i] < move[i+1]){
      east_imos[move[i]]++;
      east_imos[move[i + 1]]--;
    }else{
      west_imos[move[i] - 1]++;
      if(move[i+1]==0)continue;
      west_imos[move[i + 1]-1]--;
    }
  }
  rep(i, n-1){
    east_imos[i + 1] = east_imos[i] + east_imos[i + 1];
  }
  for (int i = n - 1; i > 0; i--){
    west_imos[i - 1] = west_imos[i] + west_imos[i - 1];
  }
  rep(i, n-1){
    sum_imos[i] = east_imos[i] + west_imos[i];
  }
  ll ans = 0;
  rep(i, n-1){
    ll a, b, c;
    cin >> a >> b >> c;
    if(a * sum_imos[i] < c + b * sum_imos[i]){
      ans += a * sum_imos[i];
    }else{
      ans += c + b * sum_imos[i];
    }
  }
  cout << ans << endl;
}