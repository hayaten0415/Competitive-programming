#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

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
  vector<ll> res = divisor(n);
  ll sum = 0;
  rep(i,res.size()){
    if(n == res[i]) continue;
    sum += res[i];
  }
  if(sum == n){
    cout << "Perfect" << endl;
  }else if(sum > n){
    cout << "Abundant" << endl;
  }else {
    cout << "Deficient" << endl;
  }
}
