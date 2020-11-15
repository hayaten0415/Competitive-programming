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
  int n;
  ll w;
  cin >> n >> w;
  vector<ll> imos(200001);
  rep(i, n){
    int s, t;
    ll p;
    cin >> s >> t >> p;
    imos[s] += p;
    imos[t] -= p;
  }
  rep(i, 200000){
    imos[i + 1] = imos[i] + imos[i + 1];
  }
  bool ok = true;
  rep(i, 200001){
    if(imos[i] > w){
      ok = false;
    }
  }
  if(ok){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}