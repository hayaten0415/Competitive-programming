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
  vector<int> place(n);
  rep(i, n){
    cin >> A[i];
    A[i]--;
    place[A[i]] = i;
  }
  int mn = -1;
  int ans = 0;
  int cn = 0;
  rep(i, n){
    if(place[i] > mn){
      cn++;
      mn = place[i];
    }else{
      chmax(ans, cn);
      cn = 1;
      mn = place[i];
    }
  }
  chmax(ans, cn);
  cout << n - ans << endl;
}