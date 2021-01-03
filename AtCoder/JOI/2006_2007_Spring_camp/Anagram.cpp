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


ll fact[21];
int main() {
  string s;
  cin >> s;
  int n = s.size();
  fact[0] = 1;
  fact[1] = 1;
  for (ll i = 2; i <= 20; i++){
    fact[i] = fact[i - 1] * i;
  }
  vector<int> cn(26);
  rep(i, n){
    cn[s[i] - 'A']++;
  }
  ll ans = 1;
  auto calc = [&](int sum, vector<int> &cn) {
    long long res = fact[sum];
    for (int i = 0; i < 26; ++i) res /= fact[cn[i]];
    return res;
  };
  for (int i = 0; i < n; ++i) {
    for (int c = 0; c < s[i]-'A'; ++c) {
        if (!cn[c]) continue;
        cn[c]--;
        ans += calc(n-i-1, cn);
        cn[c]++;
    }
    cn[s[i]-'A']--;
  }
  cout << ans << endl;
}