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

int memo[3001];
bool used[3001];

int dfs(int i,  int p){
  if(used[i])return (memo[i] % p);
  used[i] = true;
  return memo[i] = (dfs(i - 1, p) + dfs(i - 2, p)) % p;
}
int main() {
  int p;
  cin >> p;
  memo[0] = 1 % p;
  memo[1] = 1 % p;
  used[0] = true;
  used[1] = true;
  rep(i, 3001)dfs(i, p);
  rep(i, 3001){
    if(memo[i] == 0){
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}