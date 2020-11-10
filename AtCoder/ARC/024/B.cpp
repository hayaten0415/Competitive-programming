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
  rep(i, n) cin >> A[i];
  int r = 0, g = 0;
  rep(i, n){
    if(A[i] == 0)r++;
    if(A[i] == 1)g++;
  }
  if(r == n || g == n){
    cout << -1 << endl;
    return 0;
  }
  int ans = 1;
  int start_color = A[0];
  int color = start_color;
  int num = 0;
  vector<vector<int>> cn(2);
  rep(i, n){
    if(A[i] == color)num++;
    else{
      cn[color].emplace_back(num);
      num = 1;
      color = color ^ 1;
    }
  }
  cn[color].emplace_back(num);

  if(A[0] == A[n-1]){
    int left = cn[start_color][0];
    int right = cn[start_color][cn[start_color].size() - 1];
    cn[start_color][0] = left + right;
    cn[start_color].pop_back();
  }  
  sort(ALL(cn[0]), greater<int>());
  sort(ALL(cn[1]), greater<int>());
  int plus = max(cn[0][0], cn[1][0]);
  ans += (plus - 1) / 2;
  cout << ans << endl;
}