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
const int INF = (1 << 30);

int main() {
  vector<int> time(5);
  rep(i, 5) cin >> time[i];
  int ans = INF;
  sort(ALL(time));
  do{
    int sum = 0;
    rep(i, 5){
      sum += time[i];
      if(sum % 10 != 0 && i != 4){
        sum += 10 - (sum % 10);
      }
    }
    chmin(ans, sum);
  } while (next_permutation(ALL(time)));
  cout << ans << endl;
}