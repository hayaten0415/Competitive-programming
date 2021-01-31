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
  vector<P> AB(m);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--, b--;
    AB[i] = {a, b};
  }
  int k;
  cin >> k;
  vector<P> person(k);
  rep(i, k){
    int c, d;
    cin >> c >> d;
    c--, d--;
    person[i] = {c, d};
  }
  int ans = 0;
  for (int bit = 0; bit < (1 << k); bit++){
    vector<bool> ball(n, false);
    int res = 0;
    rep(i, k){
      if(bit & (1 << i)){
        ball[person[i].second] = true;
      }else{
        ball[person[i].first] = true;
      }
    }
    rep(i, m){
      if(ball[AB[i].first] && ball[AB[i].second])res++;
    }
    chmax(ans, res);
  }
  cout << ans << endl;
}