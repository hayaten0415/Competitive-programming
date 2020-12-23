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
  cin >> n;
  vector<int> A(n);
  rep(i, n){
    cin >> A[i];
    A[i]--;
  }
  vector<int> idx(n);
  ll ans = 0;
  set<int> st;
  rep(i, n) idx[A[i]] = i;
  for (int x = n - 1; x >= 0; x--){
    int i = idx[x];
    ll c = 0;
    { //calc c
      st.insert(i);
      vector<int> l(2, -1);
      vector<int> r(2, n);
      { // calc l
        auto it = st.find(i);
        rep(j, 2){
          if(it == st.begin())break;
          --it;
          l[j] = *it;
        }
      }
      { //calc r
        auto it = st.find(i);
        rep(j,2){
          it++;
          if(it == st.end())break;
          r[j] = *it;
        }
      }
      vector<int> ls(2);
      vector<int> rs(2);
      ls[0] = i - l[0]; ls[1] = l[0] - l[1];
      rs[0] = r[0] - i; rs[1] = r[1] - r[0];
      c = (ll)ls[0] * rs[1] + (ll)ls[1] * rs[0];
    }
    ans += c * (x + 1);
  }
  cout << ans << endl;
}