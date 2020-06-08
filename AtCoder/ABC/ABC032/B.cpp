#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string s;
  int k;
  cin >> s >> k;
  set<string> st;
  int n = s.size();
  if(k > n){
    cout << 0 << endl;
    return 0;
  }
  if(k == n){
    cout << 1 << endl;
    return 0;
  }
  vector<string> sum(n + 1, "");
  rep(i,n){
    sum[i + 1] = sum[i] + s[i];
  }
  for (int i = k; i < n+1; i++){
    string tmp = sum[i];
    reverse(tmp.begin(), tmp.end());
    tmp.erase(k);
    reverse(tmp.begin(), tmp.end());
    st.insert(tmp);
  }
  cout << st.size() << endl;
}