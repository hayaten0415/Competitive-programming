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
  multiset<int> sta, stb, stc;
  rep(i, n){
    int a;
    cin >> a;
    sta.insert(a);
  }
  rep(i, n){
    int a;
    cin >> a;
    stb.insert(a);
  }
  rep(i, n){
    int a;
    cin >> a;
    stc.insert(a);
  }
  int ans = 0;
  rep(i, n){
    if(sta.size() == 0 || stb.size() == 0 || stc.size() == 0)break;
    int a = *sta.begin();
    auto bp = stb.upper_bound(a);
    if(bp == stb.end())break;
    int b_tmp = *bp;
    auto cp = stc.upper_bound(b_tmp);
    if(cp == stc.end())break;
    int c_tmp = *cp;
    if(a < b_tmp && b_tmp < c_tmp){
      ans++;
      sta.erase(sta.find(a));
      stb.erase(stb.find(b_tmp));
      stc.erase(stc.find(c_tmp));
    }
  }
  cout << ans << endl;
}