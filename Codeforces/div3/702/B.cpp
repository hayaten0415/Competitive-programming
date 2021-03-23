#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
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


void solve(){
  int n;
  cin >> n;
  vector<int> A(n);
  vector<int> rest(3);
  rep(i, n) cin >> A[i];
  rep(i, n){
    rest[(A[i] % 3)]++;
  }
  int ans = 0;
  rep(i, 3){
    if(rest[i] == (n / 3))continue;
    if(rest[i] > (n / 3)){
      ans += (rest[i] - (n / 3));
      if(i < 2){
        rest[i + 1] += (rest[i] - (n / 3));
      }else{
        rest[0] += (rest[i] - (n / 3));
      }
      rest[i] -= (rest[i] - (n / 3));
    }
  }
  rep(i, 3){
    if(rest[i] == (n / 3))continue;
    if(rest[i] > (n / 3)){
      ans += (rest[i] - (n / 3));
      if(i < 2){
        rest[i + 1] += (rest[i] - (n / 3));
      }else{
        rest[0] += (rest[i] - (n / 3));
      }
      rest[i] -= (rest[i] - (n / 3));
    }
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}