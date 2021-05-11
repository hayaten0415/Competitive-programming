#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

//0-indexedに変換想定
template <typename T>
map<T, int> compress(vector<T> &X) {
  vector<T> vals = X;
  int n = vals.size();
  map<T, int> mp;
  int cn = 0;
  rep(i, n){
    mp[X[i]] = 0;
  }
  for (auto &p : mp){
    p.second = cn;
    cn++;
  }
  return mp;
}


void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  set<int> st;
  rep(i, n){
    cin >> A[i];
    st.insert(A[i]);
  }
  map<int, int> mp = compress(A);
  rep(i, n){
    A[i] = mp[A[i]] + 1;
  }
  int k = st.size();
  k = min(3, k);
  if(k == 1){
    cout << k << endl;
    rep(i, n){
      cout << 1 << " ";
    }
    cout << endl;
    return;
  }
  A.pb(A[0]);
  if(n % 2 == 0){
    cout << 2 << endl;
    rep(i, n){
      cout << i % 2 + 1 << " ";
    }
    cout << endl;
    return;
  }
  rep(i, n){
    if(A[i] == A[i+1]){
      vector<int> ans(n);
			for (int j = 0, pos = i + 1; pos < n; ++pos, j ^= 1) {
				ans[pos] = j + 1;
			}
			for (int j = 0, pos = i; pos >= 0; --pos, j ^= 1) {
				ans[pos] = j + 1;
			}
			cout << 2 << endl;
			for (int pos = 0; pos < n; ++pos) {
				cout << ans[pos] << " ";
			}
			cout << endl;
      return;
    }
  }
  cout << 3 << endl;
	rep(i, n-1){
		cout << i % 2 + 1 << " ";
	}
	cout << 3 << endl;
}



int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}