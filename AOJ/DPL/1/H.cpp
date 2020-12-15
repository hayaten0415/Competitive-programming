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
pair<ll, ll> v1[1 << 20];
int main() {
  int n;
  ll W;
  cin >> n >> W;
  vector<ll> v(n), w(n);
  ll wm = 0;
  ll vm = 0;
  rep(i, n){
    cin >> v[i] >> w[i];
  }
  int n2 = n / 2;
  for(int i = 0; i < (1 << n2); i++){
		ll tv = 0;
		ll tw = 0;
		for(int j = 0; j < n2; j++){
			if((i >> j) & 1){
				tv += v[j];
				tw += w[j];
			}
			if(tw <=W){
				v1[i] = (pll){tw, tv};
			}
		}
	}
  sort(v1, v1 + (1 << n2));
  int m=1;
	for(int i=1;i<1<<n2;i++){
		if(v1[m-1].second<v1[i].second){
			v1[m++]=v1[i];
		}
	}
  ll res=0;
	for(int i=0;i<1<<(n-n2);i++){
		ll sw=0,sv=0;
		for(int j=0;j<n-n2;j++){
			if(i>>j&1){
				sw+=w[n2+j];
				sv+=v[n2+j];
			}
		}
		if(sw<=W){
      ll tv = (lower_bound(v1, v1 + m, make_pair(W - sw, INF)) - 1)->second;
      res=max(res,sv+tv);
		}
	}
	cout << res << endl;
}