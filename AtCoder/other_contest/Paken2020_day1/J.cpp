#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<long long, long long>;
using PP = pair<P, long long>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
vector<PP> ans;
ll i = 3;
  while(true){
    if(ans.size() >= 100000)break;
    ll k = (i * i + 1)  / 2;
    ll c = k;
    ll b = k - 1;
    ll a = (ll)sqrt(c * c - b * b);
    ans.emplace_back(PP(P(a, b), c));
    i += 2;
  }
  rep(i, 100000){
    cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second << endl;
  }
}