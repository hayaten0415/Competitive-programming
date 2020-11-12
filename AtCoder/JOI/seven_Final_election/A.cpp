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
  vector<vector<int>> cn(2);
  vector<int> A(n);
  int cnt = 0;
  rep(i, n) cin >> A[i];
  int color = A[0];
  rep(i, n){
    if(i % 2 == 0){
      if(color == A[i]){
        cnt++;
      }else{
        cn[color].emplace_back(cnt);
        color = color ^ 1;
        cnt = 1;
      }
    }else{
      if(color == A[i]){
        cnt++;
      }else{
        color = color ^ 1;
        cnt++;
        if(cn[color].size() != 0){
          cnt += cn[color][cn[color].size() - 1];
          cn[color].pop_back();
        }
      }
    }
  }
  cn[color].emplace_back(cnt);
  int ans = 0;
  rep(i, cn[0].size()){
    ans += cn[0][i];
  }
  cout << ans << endl;
}