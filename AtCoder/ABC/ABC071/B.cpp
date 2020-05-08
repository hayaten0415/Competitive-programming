#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  vector<int> res(26, 0);
  rep(i, s.size()){
    int a = s[i] - 'a';
    res[a]++;
  }
  rep(i, 26) {
    if(res[i] == 0){
      char c = 'a' + i;
      cout << c << endl;
      return 0;
    }
  }
  cout << "None" << endl;
}