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

int main() {
  ll n;
  cin >> n;
  ll sum = 0;
  vector<ll> divs = divisor(n);
  rep(i,divs.size()){
    ll num = (n - divs[i]) / divs[i];
    if(divs[i] == n) continue;
    if ((((n - divs[i]) % divs[i]) == 0)){
      if(n % num == divs[i]){
        sum += num;
      }
    }
  }
  cout << sum << endl;
}