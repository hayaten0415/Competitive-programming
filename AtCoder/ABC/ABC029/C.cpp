#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

const vector<char> A = {'a', 'b', 'c'};
int n;
map<string, int> mp;

void dfs(string &s){
  if(s.size() > n) return;
  rep(i,3){
    s += A[i];
    if(s.size() == n){
      mp[s]++;
    }
    dfs(s);
    s.erase(s.size()-1);
  }
}

int main() {
  cin >> n;
  string s = "";
  dfs(s);
  for(auto i : mp){
    cout << i.first << endl;
  }
}