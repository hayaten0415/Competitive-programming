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
  vector<int> A(4);
  ll sum = 0;
  rep(i, 4){
    cin >> A[i];
    sum += A[i];
  }
  for (int bit = 1;  bit < (1 << 4); bit++){
    int eat = 0;
    rep(i, 4){
      if(bit & (1 << i)){
        eat += A[i];
      }
    }
    if(eat == sum -eat){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
