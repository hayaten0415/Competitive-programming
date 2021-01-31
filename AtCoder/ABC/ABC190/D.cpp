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
  ll N;
  cin >> N;
  N *= 2;
  vector<ll> div = divisor(N);
  int k = div.size();
  int left = 0;
  int right = k - 1;
  int ans = 0;
  while (left <= right){
    ll n = div[left];
    ll rest = div[right];
    if((rest - n + 1) % 2 == 0)ans++;
    swap(n, rest);
    if((rest - n + 1) % 2 == 0)ans++;
    left++;
    right--;
  }
  cout << ans << endl;
}