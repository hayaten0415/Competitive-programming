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
  int n;
  ll k;
  cin >> n >> k;
  vector<bitset<50>> bit(n);
  vector<ll> bit_value(n);
  vector<int> bit_num(50);
  vector<ll> two(50, 1);
  rep(i, 49){
    two[i + 1] = two[i] * 2LL;
  }
  rep(i, n){
    ll num;
    cin >> num;
    bit_value[i] = num;
    bit[i] = bitset<50>(num);
    string s = bit[i].to_string();
    reverse(ALL(s));
    rep(j, 50){
      if(s[j] == '1')bit_num[j]++;
    }
  }
  bitset<50> tmp1(0), tmp2(0);
  int t = upper_bound(ALL(two), k) - two.begin();
  if(t > 0)t--;
  ll tmp = 0;
  rrep(i, 50){
    if(bit_num[i] < (n + 1)/ 2){
      if(tmp + two[i] <= k){
        tmp2.set(i);
        tmp += two[i];
      }
    }
  }
  rep(i, t){
    if(bit_num[i] < (n + 1)/ 2){
      tmp1.set(i);
    }
  }
  ll res1 = tmp1.to_ullong();
  ll res2 = tmp2.to_ullong();
  ll ans1 = 0;
  ll ans2 = 0;
  rep(i, n){
    ans1 += res1 ^ bit_value[i];
    ans2 += res2 ^ bit_value[i];
  }
  cout << max(ans1, ans2) << endl;
}