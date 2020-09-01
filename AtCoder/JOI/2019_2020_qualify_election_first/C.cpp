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
  int n, m;
  cin >> n >> m;
  vector<int> A(n), B(m), ans;
  rep(i, n) cin >> A[i];
  rep(i, m) cin >> B[i];
  int a_index = 0;
  int b_index = 0;
  while(a_index < n && b_index < m){
    if(A[a_index] <= B[b_index]){
      ans.emplace_back(A[a_index]);
      a_index++;
    }else{
      ans.emplace_back(B[b_index]);
      b_index++;
    }
  }
  rep(i, ans.size()){
    cout << ans[i] << endl;
  }
  if(a_index >= n){
    while (b_index < m){
      cout << B[b_index] << endl;
      b_index++;
    }
  }else{
    while (a_index < n){
      cout << A[a_index] << endl;
      a_index++;
    }
  }
  
}