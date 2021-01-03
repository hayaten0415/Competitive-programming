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
  int n;
  cin >> n;
  vector<string> s(n);
  set<string> st;
  rep(i, n){
    cin >> s[i];
    st.insert(s[i]);
  }
  string res;
  bool ok = true;
  rep(i, n){
    string tmp = '!' + s[i];
    if(st.find(tmp) != st.end() && st.find(s[i]) != st.end()){
      cout << s[i] << endl;
      return 0;
    }
  }
  cout << "satisfiable" << endl;
}