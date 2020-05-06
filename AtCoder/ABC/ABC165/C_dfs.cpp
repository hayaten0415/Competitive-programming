#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int n, m, q;
vector<ll> a, b, c, d;

ll score(vector<int> &A){
  ll sc = 0;
  rep(i,q){
    if(A[b[i]] - A[a[i]] == c[i]) sc += d[i];
  }
  return sc;
}

ll recur(vector<int> &A) {
  if(A.size() == n) return score(A);
  ll ans = 0;
  int last = (A.empty()? 0:A.back());
  for (int i = last; i < m;i++){
    A.push_back(i);
    ans = max(ans, recur(A));
    A.pop_back();
  }
  return ans;
}

int main() {
  cin >> n >> m >> q;
  a.resize(q);
  b.resize(q);
  c.resize(q);
  d.resize(q);
  rep(i, q){
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    a[i]--, b[i]--;
  }
  vector<int> A;
  cout << recur(A) << endl;
}