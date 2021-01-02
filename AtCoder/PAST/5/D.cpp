#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<string, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int Judge(P x, P y){
  if(x.first.size() != y.first.size()){
    return x.first.size() < y.first.size();
  }else if(x.first.size() == y.first.size() && x.first != y.first){
    return x.first < y.first;
  }else{
    return x.second > y.second;
  }
}


int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  vector<P> ans(n);
  rep(i, n){
    cin >> s[i];
    string tmp = "";
    bool non_zero = false;
    int k = s[i].size();
    string zero = string(k,'0');
    if(s[i] == zero){
      ans[i] = P(tmp,k);
      continue;
    }
    int num = 0;
    rep(j, k){
      if(s[i][j] != '0' && !non_zero){
        tmp = s[i].substr(j, k);
        break;
      }
      if(!non_zero)num++;
    }
    ans[i] = P(tmp, num);
  }
  sort(ans.begin(), ans.end(), Judge);
  rep(i, n){
    string tmp = string(ans[i].second, '0');
    string res = tmp + ans[i].first;
    cout << res << "\n";
  }
}