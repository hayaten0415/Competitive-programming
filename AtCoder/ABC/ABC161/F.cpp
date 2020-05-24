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
  vector<ll> ans1 = divisor(n - 1);
  vector<ll> ans2 = divisor(n);
  //n-1の約数のうち1は含めない
  ll ans = ans1.size()-1;
  for (int i = 1; i < ans2.size(); i++){
    ll num = n;
    while(num % ans2[i] == 0){
      num /= ans2[i];
    }
    if(num % ans2[i] == 1) ans++;
  }
  cout << ans << endl;
}