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
const int nx[2] = {0, -1};
const int ny[2] = {-1, 0};

int main() {
  int n = 13;
  int k = 26;
  vector<string> ans(n, "aaaaaaaaaaaaa");
  vector<set<int>> cn(26);
  ans[0] = "abcdefghijklm";
  ans[1] = "nopqrstuvwxyz";
  rep(i, 2){
    rep(j, n){
      int f = ans[i][j] - 'a';
      rep(d, 2){
        int next_i = i + dy[d];
        int next_j = j + dx[d];
        if(next_i >= 2 || next_j >= n)continue;
        int t = ans[next_i][next_j] - 'a';
        cn[f].insert(t);
      }
    }
  }
  for (int i = 2; i < n; i++){
    rep(j, n){
      while(true){
        int t = rand() % 26;
        bool ok = true;
        rep(e, 2){
          int prev_i = i + ny[e];
          int prev_j = j + nx[e];
          if(prev_i < 0 || prev_j < 0)continue;
          int f = ans[prev_i][prev_j] - 'a';
          //cout << f << endl;
          if(cn[f].find(t) != cn[f].end()){
            ok = false;
          }
        }
        if(ok){
          char c = t + 'a';
          ans[i][j] = c;
          rep(e, 2){
            int prev_i = i + ny[e];
            int prev_j = j + nx[e];
            if(prev_i < 0 || prev_j < 0)continue;
            int f = ans[prev_i][prev_j] - 'a';
            cn[f].insert(t);
          }
          break;
        }
      }
    }
  }
  cout << n << endl;
  rep(i, n){
    cout << ans[i] << endl;
  }
}