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
  vector<int> A(5);
  rep(i, 5) cin >> A[i];
  vector<int> sum;
  for (int i = 0; i < 5; i++){
    for (int j = i + 1; j < 5; j++){
      for (int k = j + 1; k < 5; k++){
        sum.emplace_back(A[i] + A[j] + A[k]);
      }
    }
  }
  sort(ALL(sum), greater<int>());
  cout << sum[2] << endl;
}