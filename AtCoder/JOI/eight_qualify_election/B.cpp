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
  vector<int> W(10), K(10);
  rep(i, 10) cin >> W[i];
  rep(i, 10) cin >> K[i];
  sort(ALL(W), greater<int>());
  sort(ALL(K), greater<int>());
  cout << W[0] + W[1] + W[2] << " ";
  cout << K[0] + K[1] + K[2] << endl;
}