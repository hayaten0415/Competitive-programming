#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string s;
  getline(cin, s);
  vector<string> ans;
  //空白文字で区切る
  regex separator{" "};
  auto ite = std::sregex_token_iterator(s.begin(), s.end(), separator, -1);
  auto end = std::sregex_token_iterator();
  while (ite != end) {
    ans.push_back(*ite++);     // 分割文字列を格納
  }
  int num = ans.size();
  int n;
  cin >> n;
  vector<string> ban(n);
  rep(i, n){
    cin >> ban[i];
    rep(j,num){
      if(ban[i].size() != ans[j].size())continue;
      int c = 0;
      bool ng = true;
      int cn = ban[i].size();
      while(c < cn){
        if(ban[i][c] == '*'){
          c++;
          continue;
        }
        if(ban[i][c] != ans[j][c]){
          ng = false;
          break;
        }
        c++;
      }
      if(ng){
        rep(m,cn){
          ans[j][m] = '*';
        }
      }
    }
  }
  rep(i,num){
    cout << ans[i] << (i == num - 1 ? "\n" : " ");
  }
}