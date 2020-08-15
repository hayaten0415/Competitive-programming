#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  rep(i, n) {
    rep(j, n) {
      cout << ((2 * i - j + n) % n + 1) << " ";
    }
    cout << "\n";
  }
}