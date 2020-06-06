#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

const int MOD = 1000000007;
const int MAX = 200000;

int main() {
  ll n, k;
  ll m, r;
  cin >> n >> k >> m >> r;
  vector<ll> s(n - 1);
  ll sum = 0;
  ll now_point = 0;
  rep(i, n - 1){
    cin >> s[i];
    sum += s[i];
  }
  sort(s.begin(), s.end(), greater<ll>());
  ll limit = k * r;
  if(k == n){
    if(sum >= limit){
      cout << 0 << endl;
    }else if(sum + m < limit){
      cout << -1 << endl;
    }else{
      cout << limit - sum << endl;
    }
  }else {
    rep(i, k-1) now_point += s[i];
    if(now_point + s[k-1] >= limit){
      cout << 0 << endl;
    }else if(now_point + m < limit){
      cout << -1 << endl;
    }else{
      cout << limit - now_point << endl;
    }
  }
}