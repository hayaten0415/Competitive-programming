#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll INF = (1LL <<60);

int main() {
  int n;
  cin >> n;
  vector<ll> A(n), B(n);
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> B[i];
  multiset<ll> st;
  rep(i, n) st.insert(B[i]);
  vector<ll> res;
  set<ll> ans;
  rep(i, n) res.push_back(A[0] ^ B[i]);
  rep(i, n){
    multiset<ll> tmp = st;
    tmp.erase(tmp.find(B[i]));
    for (int j = 1; j < n; j++){
      ll d = res[i] ^ A[j];
      if(tmp.find(d) == tmp.end()){
        break;
      }
      tmp.erase(tmp.find(d));
    }
    if(tmp.size() > 0)continue;
    ans.insert(res[i]);
  }
  cout << ans.size() << endl;
  for(auto d: ans){
    cout << d << endl;
  }
}