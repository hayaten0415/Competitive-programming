#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string s;
  int k;
  cin >> s >> k;
  int n = s.size();
  set<string> res;
  int right = 0;
  rep(i, n){
    string tmp = "";
    tmp += s[i];
    res.insert(tmp);
    for (int j = i + 1; j < n; j++){
      tmp += s[j];
      if(tmp.size() > k)break;
      res.insert(tmp);
    }
  }
  int index = 1;
  for(auto itr = res.begin(); itr != res.end(); ++itr) {
    if(index == k){
      cout << *itr << "\n";
      return 0;
    }
    index++;
  }
}