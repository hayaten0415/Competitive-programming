//https://ei1333.github.io/luzhiled/snippets/string/manacher.html
#include <bits/stdc++.h>
using namespace std;

vector< int > manacher(string &s) {
  int n = s.size();
  string res = "";
  for(int i = 0; i < n; i++){
      res += s[i];
      if(i != n-1){
          res += '$';
      }
  }
  s = res;
  vector< int > radius(s.size());
  int i = 0, j = 0;
  while(i < s.size()) {
      while(i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]) {
          ++j;
      }
      radius[i] = j;
      int k = 1;
      while(i - k >= 0 && i + k < s.size() && k + radius[i - k] < j) {
          radius[i + k] = radius[i - k];
          ++k;
      }
      i += k;
      j -= k;
  }
  return radius;
}

// evenをtrueにした場合は偶数文字の回文、ダミー文字として'$'を入れることを想定
string restore_manacher(vector<int> &radius, string &s, bool even = false){
  int mxlen = 0;
  int id = -1;
  int n = s.size();
  for(int i = 0; i < n; i++){
    if(even & s[i] != '$')continue;
    if(mxlen < radius[i]){
      mxlen = radius[i];
      id = i;
    }
  }
  string res1 = "";
  for(int i = id; i < id + mxlen; i++){
    if(s[i] == '$')continue;
    res1 += s[i];
  }
  string res2 = res1;
  reverse(res2.begin(), res2.end());
  if(!even){
    res2.pop_back();
  }
  return res2 + res1;
}