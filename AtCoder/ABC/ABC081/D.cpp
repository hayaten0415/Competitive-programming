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
  int mx_index = 0;
  int mx = 0;
  rep(i, n){
    cin >> A[i];
    if(abs(mx) < abs(A[i])){
      mx = A[i];
      mx_index = i;
    }
  }
  if(mx ==0){
    cout << 0 << endl;
    return 0;
  }
  vector<P> ans;
  if(mx > 0){
    rep(i, n){
      if(A[i] < 0){
        A[i] += mx;
        ans.emplace_back(P(mx_index + 1, i + 1));
      }
    }
    rep(i, n){
      if(A[i] < mx){
        A[i] += mx;
        ans.emplace_back(P(mx_index + 1, i + 1));
        mx = A[i];
        mx_index = i;
      }
    }
  }else{
    rep(i, n){
      if(A[i] > 0){
        A[i] += mx;
        ans.emplace_back(P(mx_index + 1, i + 1));
      }
    }
    rrep(i, n){
      if(A[i] > mx){
        A[i] += mx;
        ans.emplace_back(P(mx_index + 1, i + 1));
        mx = A[i];
        mx_index = i;
      }
    }
  }
  cout << ans.size() << endl;
  rep(i, ans.size()){
    cout << ans[i].first << " " << ans[i].second << endl;
  }
}