#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  if(n == 1){
    cout << "Yes" << endl;
    return 0;
  }
  //文字列sについてどのアルファベットが初めて何文字目に出てきてたかを管理するvector
  vector<int> alpha_s(26, -1);
  //文字列tについてどのアルファベットが初めて何文字目に出てきてたかを管理するvector
  vector<int> alpha_t(26, -1);
  vector<vector<int>> compose_s(n);
  vector<vector<int>> compose_t(n);
  rep(i, n){
    int s_i = s[i] - 'a';
    int t_i = t[i] - 'a';
    if(alpha_s[s_i] == -1){
      alpha_s[s_i] = i;
    }
    if(alpha_t[t_i] == -1){
      alpha_t[t_i] = i;
    }
    compose_s[alpha_s[s_i]].push_back(i);
    compose_t[alpha_t[t_i]].push_back(i);
  }
  if(compose_s == compose_t){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}