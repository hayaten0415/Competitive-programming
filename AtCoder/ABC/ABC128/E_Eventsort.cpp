#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
using PP = pair<int, P>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};


int main() {
  int n, q;
  cin >> n >> q;
  set<int> st;
  vector<PP> Query;
  rep(i, n){
    int s, t, x;
    cin >> s >> t >> x;
    Query.pb({s - x, {1, x}});
    Query.pb({t - x, {0, x}});
  }
  rep(i, q){
    int d;
    cin >> d;
    Query.pb({d, {2, i}});
  }
  sort(ALL(Query));
  vector<int> ans(q);
  for(auto p : Query){
    if(p.second.first == 0){
      int pos = p.second.second;
      st.erase(pos);
    }else if(p.second.first == 1){
      int pos = p.second.second;
      st.insert(pos);
    }else{
      int pos = p.second.second;
      if(!st.empty()){
        ans[pos] = *st.begin();
      }else{
        ans[pos] = -1;
      }
    }
  }
  rep(i, q){
    cout << ans[i] << endl;
  }
}