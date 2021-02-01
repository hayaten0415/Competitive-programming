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

vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}

int main() {
  ll n;
  cin >> n;
  n *= 2;
  vector<ll> div = divisor(n);
  int d = div.size();
  if(div[d / 2] -1 != div[d/ 2 -1] || n == 4){
    cout << "No" << endl;
    return 0;
  }
  ll k = div[d / 2];
  ll c = k - 1;
  vector<vector<ll>> A(k);
  ll tmp = 1;
  rep(i, k){
    for (int j = i + 1; j < k; j++){
      A[i].emplace_back(tmp);
      A[j].emplace_back(tmp);
      tmp++;
    }
  }
  cout << "Yes" << endl;
  cout << k << endl;
  rep(i, k){
    cout << c << " ";
    rep(j, c){
      cout << A[i][j] << (j == c - 1 ? "\n" : " ");
    }
  }
}