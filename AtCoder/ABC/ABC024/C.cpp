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
  int n, d, k;
  cin >> n >> d >> k;
  vector<int> L(d), R(d);
  rep(i, d){
    cin >> L[i] >> R[i];
  }
  vector<int> ans(k), goal(k), now(k), right(k, 0);
  rep(i, k){
    cin >> now[i] >> goal[i];
    if(now[i] < goal[i])right[i] = 1;
  }
  rep(i, k){
    rep(j, d){
      if(now[i] >= L[j] && now[i] <= R[j]){
        if(right[i] == 1){
          now[i] = R[j];
          if(now[i] >= goal[i]){
            ans[i] = j + 1;
            break;
          }
        }else{
          now[i] = L[j];
          if(now[i] <= goal[i]){
            ans[i] = j + 1;
            break;
          }
        }
      }
    }
  }
  rep(i, k){
    cout << ans[i] << endl;
  }
}