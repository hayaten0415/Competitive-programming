#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
vector<string> res;
int n;

void dfs(string tmp, char mx){
  if(tmp.size() == n){
    res.push_back(tmp);
    return;
  }
  for(char c ='a'; c<= mx; c++){
    dfs(tmp + c, ((c == mx)? (char) (mx + 1) : mx));
  }
}

int main() {
  cin >> n;
  string tmp = "";
  dfs(tmp, 'a');
  sort(ALL(res));
  rep(i, res.size()){
    cout << res[i] << endl;
  }
}