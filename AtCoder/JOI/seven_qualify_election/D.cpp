#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int m,n;
  cin >> m;
  vector<int> sx(m), sy(m);
  rep(i, m) cin >> sx[i] >> sy[i];
  set<P> st;
  cin >> n;
  vector<int> x(n), y(n);
  rep(i, n) {
    cin >> x[i] >> y[i];
    st.insert({x[i], y[i]});
  }
  rep(i, n) {
    int dx = x[i] - sx[0];
    int dy = y[i] - sy[0];
    bool ok = true;
    rep(j, m) {
      if(st.find({sx[j]+dx,sy[j] + dy}) == st.end()) ok = false;
    }
    if(ok){
      cout << dx << " " << dy << endl;
    }
  }
}