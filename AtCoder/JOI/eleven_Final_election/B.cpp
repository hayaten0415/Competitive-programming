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

int a, b;
int ans = 0;
vector<vector<int>> st;
void search(int i, int j, int cn){
  if(i == b-1){
    chmax(ans, cn);
    return;
  }
  if(j == a-1){
    chmax(ans, cn);
    return;
  }
  if(ans == min(a, b))return;
  if(st[i+1].size() == 0){
    chmax(ans, cn);
    return;
  }
  int k = upper_bound(ALL(st[i + 1]), j)- st[i+1].begin();
  if(st[i+1].size() == k){
    chmax(ans, cn);
    return;
  }
  search(i + 1, st[i + 1][k], cn + 1);
}

int main() {
  cin >> a >> b;
  vector<int> s(a), t(b);
  rep(i, a) cin >> s[i];
  rep(i, b) cin >> t[i];
  st.resize(b);
  rep(j, b){
    rep(i, a){
      if(s[i] == t[j]){
        st[j].emplace_back(i);
      }
    }
  }
  rep(i, b){
    if(st[i].size() == 0)continue;
    int num = st[i][0];
    search(i, num, 1);
  }
  cout << ans << endl;
}
