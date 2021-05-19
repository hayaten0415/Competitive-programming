#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
using namespace std;
using P = pair<int, int>;
using PL = pair<long long, long long>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};


void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> A(n);
  vector<int> ans(n);
  set<int> st;
  rep(i, n){
    cin >> A[i];
  }
  ans = A;
  sort(ALL(ans));
  rep(i, m){
    int a;
    cin >> a;
    a--;
    st.insert(a);
  }
  while (true) {
		bool ok = false;
		for (int i = 0; i < n-1; i++) {
			if (st.find(i) !=st.end() && A[i] > A[i + 1]) {
				ok = true;
				swap(A[i], A[i + 1]);
			}
		}
		if (!ok) break;
	}
	bool ok = true;
	for (int i = 0; i < n - 1; ++i) {
		ok &= A[i] <= A[i + 1];
	}
	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}