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
  int n, k;
  cin >> n >> k;
  vector<int> ans(k);
  rep(i, k){
    int a, b;
    cin >> a >> b;
    if(a > (n + 1) /2) a = n - a + 1;
    if(b > (n + 1) /2) b = n - b + 1;
    ans[i] = ((min(a, b) -1) % 3) + 1;
  }
  rep(i, k){
    cout << ans[i] << endl;
  }
}