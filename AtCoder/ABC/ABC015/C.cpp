#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

bool dfs(vector<vector<int>> &t, int n, int k, int cn, int num){
  if(cn == n){
    return (num == 0);
  }
  rep(i,k){
    if(dfs(t, n, k,cn+1, num ^ t[cn][i])) return true;
  }
  return false;
}

int main() {
  int n, k;
  cin >> n >> k;
  int num = 0;
  vector<vector<int>> t(n, vector<int>(k));
  rep(i, n){
    rep(j, k){
      cin >> t[i][j];
    }
  }
  bool ans = dfs(t, n, k, 0, 0);
  if(ans){
    cout << "Found" << endl;
  }else{
    cout << "Nothing" << endl;
  }
}