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
  vector<P> card(m);
  int ans = 0;
  int ok = 0;
  rep(i,m){
    int a, b;
    cin >> a >> b;
    card[i] = {a, b};
    if(a >= n)ok++;
  }
  if(ok >= m-1){
    cout << 0 << endl;
    return 0;
  }
  sort(ALL(card));
  rrep(i, m){
    if(ok >= m-1)break;
    if(n - card[i].first <= 0)continue;
    ans += n - card[i].first;
    ok++;
  }
  cout << ans << endl;
}