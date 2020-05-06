#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

//約数列挙 計算量O(sqrt(n))
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

ll f(ll a, ll b){
  ll a_count = 1;
  ll b_count = 1;
  while(a >= 10){
    a_count++;
    a /= 10;
  }
  while (b >= 10){
    b_count++;
    b /= 10;
  }
  return max(a_count, b_count);
}

int main() {
  ll n;
  cin >> n;
  ll ans = 1000000000000;
  vector<ll> divs = divisor(n);
  int left = 0;
  int right = divs.size() - 1;
  while(right - left >= 0){
    ll num = f(divs[left], divs[right]);
    ans = min(ans, num);
    left++;
    right--;
  }
  cout << ans << endl;
}