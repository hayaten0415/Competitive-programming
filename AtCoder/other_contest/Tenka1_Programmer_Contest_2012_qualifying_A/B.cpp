#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string s;
  getline(cin, s);
  vector<string> ans;
  int n = s.size();
  regex separator{" +"};
  auto ite = std::sregex_token_iterator(s.begin(), s.end(), separator, -1);
  auto end = std::sregex_token_iterator();
  while (ite != end) {
    ans.push_back(*ite++);     // 分割文字列を格納
  }
  int num = ans.size();
  rep(i, num){
    cout << ans[i] << (i == num - 1 ? "\n" : ",");
  }
}