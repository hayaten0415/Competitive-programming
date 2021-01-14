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
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  vector<ll> S1(26), S2(26), S3(26);
  int n = s1.size();
  rep(i, n){
    int d = s1[i] - 'A';
    int e = s2[i] - 'A';
    int f = s3[i] - 'A';
    S1[d]++;
    S2[e]++;
    S3[f]++;
  }
  bool ok = true;
  ll mn = 0;
  ll mx = 0;
  rep(i, 26){
    if(S1[i] + S2[i] < S3[i])ok = false;
    mn += max(S3[i] - S2[i], 0LL);
    mx += min(S1[i], S3[i]);
  }
  if (ok && mn <= n / 2 && n / 2 <= mx){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}