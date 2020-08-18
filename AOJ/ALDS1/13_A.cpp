#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
bool ok = true;

void dfs(int h, int w, vector<string> &tmp) {
  for (int j = 1; j < 8; j++){
    if (h + j < 8 && w + j < 8 && tmp[h + j][w + j] == 'Q'){
      ok = false;
      return;
    }
    if (h + j < 8 && w - j >= 0 && tmp[h + j][w - j] == 'Q'){
      ok = false;
      return;
    }
    if (h - j >= 0 && w + j < 8 && tmp[h - j][w + j] == 'Q'){
      ok = false;
      return;
    }
    if (h - j >= 0 && w - j >= 0 && tmp[h - j][w - j] == 'Q'){
      ok = false;
      return;
    }
  }
  return;
}

int main() {
  int k;
  cin >> k;
  vector<int> used_row(8, -1);
  vector<int> a(8);
  vector<string> grid(8, "........");
  rep(i, k) {
    int x, y;
    cin >> x >> y;
    grid[x][y] = 'Q';
    used_row[x] = y;
  }
  rep(i, 8) a[i] = i;
  sort(ALL(a));
  do{
    ok = true;
    vector<string> tmp = grid;
    vector<int> Q;
    rep(i, 8) {
      if(used_row[i] != -1 && used_row[i] != a[i]){
        ok = false;
        break;
      }
      tmp[i][a[i]] = 'Q';
      Q.emplace_back(a[i]);
    }
    rep(i, 8) {
      if(!ok)break;
      dfs(i, Q[i], tmp);
    }
    if(ok){
      rep(i, 8) {
        cout << tmp[i] << endl;
      }
      return 0;
    }
  } while (next_permutation(a.begin(),a .end()));
  
}