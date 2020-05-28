#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;
const int INF = 1001001001;

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  int ans = INF;
  vector<string> chocolate(h);
  rep(i, h) cin >> chocolate[i];
  for(int bit = 0; bit< (1 << h-1); bit++){
    int g = 0;
    vector<int> id(h);
    rep(i,h){
      id[i] = g;
      if(bit >> i & 1) g++;
    }
    g++;

    vector<vector<int>> c(h, vector<int>(w, 0));
    rep(i, h) rep(j, w) c[id[i]][j] += (chocolate[i][j] - '0');
    int num = g - 1;
    vector<int> now(g);
    auto add = [&](int j) {
      rep(i, g) now[i] += c[i][j];
      rep(i, g) if (now[i] > k) return false;
      return true;
    };
    rep(j,w) {
      if (!add(j)) {
        num++;
        now = vector<int>(g);
        if (!add(j)) {
          num = INF;
          break;
        }
      }
    }
    ans = min(ans, num);
  }
  cout << ans << endl;
}