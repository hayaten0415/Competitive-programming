#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
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
  ll h, w;
  cin >> h >> w;
  ll num = gcd(h, w);
  h /= num;
  if(h == 4){
    cout << "4:3" << endl;
  }else {
    cout << "16:9" << endl;
  }
}