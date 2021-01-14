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
  vector<ll> C(n-1), S(n-1),F(n-1);
  vector<ll> ans(n, 0);
  rep(i, n-1){
    cin >> C[i] >> S[i] >> F[i];
    ans[i] = S[i];
  }
  rep(i, n-1){
    for (int j = i; j < n-1; j++){
      ans[i] += C[j];
      if(j == n-2)break;
      if(ans[i] < S[j+ 1])ans[i] = S[j+1];
      else{
        if(((ans[i] - S[j+1]) % F[j+1]) == 0)continue;
        ll rest = (ans[i] - S[j + 1]) % F[j + 1];
        ans[i] += F[j + 1] - rest;
      }
    }
  }
  rep(i, n){
    cout << ans[i] << endl;
  }
}