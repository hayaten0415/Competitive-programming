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
  double pas[1001[1001];
  double t = 1;
  rep(i, 1001){
    pas[i][0] = pas[0][i] = t;
    t /= (double)2;
  }
  for(int i = 1; i < 1001; i++){
    for (int j = 1; j < 1001; j++){
      if(i+j<=1001){
				pas[i][j] = (pas[i - 1][j] + pas[i][j - 1])/double(2);
			}
    }
  }
}