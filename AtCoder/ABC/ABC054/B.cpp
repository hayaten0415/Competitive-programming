#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int n, m;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

bool contains_square(int y, int x, vector<string> &A, vector<string> &B){
  if(y + m > n) return false;
  if(x + m > n) return false;
  for (int i = 0; i < m; i++){
    for (int j = 0; j < m; j++){
      if(A[y+i][x+j] != B[i][j]) return false;
    }
  }
  return true;
}

int main() {
  cin >> n >> m;
  bool ok = false;
  vector<string> A(n);
  rep(i, n) cin >> A[i];
  vector<string> B(m);
  rep(i,m) cin >> B[i];
  rep(i,n){
    rep(j,n){
      ok = contains_square(i, j, A, B);
      if(ok){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}