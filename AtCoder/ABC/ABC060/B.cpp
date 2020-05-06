#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

ll gcd(ll a, ll b) {
  ll smaller = min(a, b);
  ll bigger = max(a, b);
  ll surplus = bigger % smaller;
  if (surplus == 0) return smaller;
  surplus = gcd(smaller, surplus);
  return surplus;
}

int main() {
  ll a, b, c;
  cin >> a >> b >>c;
  if(c % gcd(a,b) == 0){
    cout << "YES" << endl;
  }else {
    cout << "NO" << endl;
  }
}