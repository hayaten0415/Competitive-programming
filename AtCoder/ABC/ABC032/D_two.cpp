#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = (1LL << 50);

int main() {
  int n;
  ll W;
  cin >> n >> W;
  vector<ll> v(n), w(n);
  ll wm = 0;
  ll vm = 0;
  rep(i, n){
    cin >> v[i] >> w[i];
    chmax(vm, v[i]);
    chmax(wm, w[i]);
  }
  if(n <= 30){
    int n1 = n / 2;
    int n2 = n - n1;
    vector<pll> v1, v2;
    for(int i = 0; i < (1 << n1); i++){
			ll tv = 0;
			ll tw = 0;
			for(int j = 0; j < n1; j++){
				if((i >> j) & 1){
					tv += v[j];
					tw += w[j];
				}
				if(tw <=W){
					v1.push_back((pll){tw, tv});
				}
			}
		}
    for(ll i = 0; i < (1 << n2); i++){
			ll tv = 0;
			ll tw = 0;
			for(ll j = n1; j < n1 + n2; j++){
				if((i >> (j - n1)) & 1){
					tv += v[j];
					tw += w[j];
				}
				if(tw <= W){
					v2.push_back((pll){tw, tv});
				}
			}
		}
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    ll m1 = v1.size();
    ll m2 = v2.size();
    ll ans = 0LL;
    ll ma = 0LL;
    ll j = 0LL;
    for(ll i = m1-1; i >= 0; i--){
			pll p1 = v1[i];
			while(j < m2 && p1.first + v2[j].first <= W){
				ma = max(ma, v2[j].second);
				j++;
			}
			ans = max(ans, p1.second + ma);
		}
		cout << ans << endl;
  }else if(wm <= 1000){
    vector<vector<ll>> dp(n + 1, vector<ll>(200001));
    rep(i, n){
      rep(j, W+1){
        if(j < w[i]){
          dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
        }else{
          dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
        }
      }
    }
  cout << dp[n][W] << endl;
  }else{
    vector<vector<ll>> dp(n + 1, vector<ll>(200001, INF));
    dp[0][0] = 0;
    for (int i = 1; i < n + 1; i++) {
      for (int j = 0; j < 200001; j++){
        if(j - v[i-1] >= 0){
          dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i-1]] + w[i-1]);
        }else {
          dp[i][j] = min(dp[i][j], dp[i - 1][j]);
        }
      }
    }
    int ans = 200000;
    while(dp[n][ans] > W)ans--;
    cout << ans << endl;
  }
}