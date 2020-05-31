#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

const int MOD = 1000000007;
const int MAX = 200000;

int main() {
  long double a;
  long double b;
  cin >> a >> b;
  long double ans = a * b;
  ll res = (ll)floorl(ans);
  cout << res << endl;
}
