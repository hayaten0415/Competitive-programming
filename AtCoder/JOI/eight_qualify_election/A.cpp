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
  rep(i, 3){
    int h1, m1, s1, h2, m2, s2;
    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
    int ans = 0;
    ans += 3600 * (h2 - h1);
    ans += 60 * (m2 - m1);
    ans += (s2 - s1);
    int ans1 = ans / 3600;
    ans -= 3600 * ans1;
    int ans2 = ans / 60;
    ans -= 60 * ans2;
    cout << ans1 << " " << ans2 << " " << ans << "\n";
  }
}