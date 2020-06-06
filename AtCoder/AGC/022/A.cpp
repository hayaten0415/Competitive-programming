#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  if(s == "zyxwvutsrqponmlkjihgfedcba"){
    cout << -1 << endl;
    return 0;
  }
  vector<bool> used(26, false);
  int n = s.size();
  if(n < 26){
    rep(i,n){
      int a = s[i] - 'a';
      used[a] = true;
    }
    rep(i, 26){
      if(!used[i]){
        char c = i + 'a';
        s += c;
        cout << s << endl;
        return 0;
      }
    } 
  }
  vector<char> ve;
  rep(i,26){
    ve.push_back(s[i]);
  }
  if(next_permutation(ve.begin(), ve.end())){
    string t = "";
    rep(i, ve.size()){
      t += ve[i];
      if(s[i] != ve[i])break;
    }
    cout << t << endl;
    return 0;
  }
}