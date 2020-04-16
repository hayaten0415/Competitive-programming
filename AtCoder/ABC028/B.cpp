#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  map<char, int> M;
  for(char c:s)M[c]++;
  for(char i='A';i<='F';i++)cout<<M[i]<<(i=='F'?"\n":" ");
}