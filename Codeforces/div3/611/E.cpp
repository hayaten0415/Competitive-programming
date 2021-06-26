#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};



int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  rep(i, n) cin >> x[i];
  sort(ALL(x));
  vector<int> ok(n + 2);
  auto mx_num = [&](){
    rep(i, n){
      if(ok[x[i] -1] == 0){
        ok[x[i] - 1] = 1;
        continue;
      }
      if(ok[x[i]] == 0){
        ok[x[i]] = 1;
        continue;
      }
      if(ok[x[i] + 1] == 0){
        ok[x[i] + 1] = 1;
        continue;
      }
    }
    return accumulate(ALL(ok), 0);
  };
  auto mn_num = [&]() {
    vector<int> cn(n + 2);
    rep(i, n) cn[x[i]]++;
    int ans = 0;
    rep(i, n+2){
      if(cn[i] == 0)continue;
      ans++;
      i += 2;
    }
    return ans;
  };
  cout << mn_num() << " " << mx_num() << endl;
}