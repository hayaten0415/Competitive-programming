#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const int MOD = 1000000007;
const int MAX =200000;

int main() {
  string s;
  string head = "";
  string tail = "";
  int flip = 0;
  int q;
  int t;
  int f;
  string c;
  cin >> s >> q;
  rep(i, q) {
    cin >> t;
    if(t == 1) {
      flip ^= 1;
    } else {
      cin >> f >> c;
      f--;
      if (f ^ flip == 0){
        head += c;
      } else {
        tail += c;
      }
    }
  }
  if(flip){
    swap(head, tail);
    reverse(s.begin(), s.end());
  }
  reverse(head.begin(), head.end());

  cout << (head + s + tail) << endl;
}