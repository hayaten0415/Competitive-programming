#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int r, c, d;
  int mx = 0;
  cin >> r >> c >> d;
  bool even_number = (d % 2 == 0);
  vector<vector<int>> A(r, vector<int>(c));
  rep(i, r){
    rep(j, c){
      cin >> A[i][j];
      if(i + j > d)continue;
      if(even_number){ 
        if((i + j) % 2 == 0)mx = max(mx, A[i][j]);
      }else{ 
        if ((i + j) % 2 == 1)mx = max(mx, A[i][j]);
      }
    }
  }
  cout << mx << endl;
}