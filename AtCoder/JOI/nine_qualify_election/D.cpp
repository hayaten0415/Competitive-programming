#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int n, k;
  cin >> n >> k;
  set<string> st;
  vector<string> A(n);
  rep(i, n){
    cin >> A[i];
  }
  for (int bit = 1; bit < (1 << n); bit++){
    vector<string> tmp;
    rep(i, n){
      if(bit & (1 << i)){
        tmp.emplace_back(A[i]);
      }
    }
    if(tmp.size() != k)continue;
    sort(ALL(tmp));
    do{
      string ans = "";
      rep(i, k){
        ans += tmp[i];
      }
      st.insert(ans);
    } while (next_permutation(ALL(tmp)));
  }
  cout << st.size() << endl;
}