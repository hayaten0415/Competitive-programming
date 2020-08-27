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
  vector<int> X(n);
  rep(i, n){
    cin >> X[i];
    X[i]--;
  }
  int m;
  cin >> m;
  vector<int> A(m);
  rep(i, m){
    cin >> A[i];
    A[i]--;
  }
  rep(i, m){
    if(A[i] < n-1 && X[A[i]] + 1 == X[A[i] + 1])continue;
    if(X[A[i]] == 2018)continue;
    X[A[i]]++;
  }
  rep(i, n){
    cout << X[i] + 1 << endl;
  }
}