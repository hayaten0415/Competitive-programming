#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int s;
  cin >> s;
  int left = s / 100;
  int right = s % 100;
  if(1 <= left && left <= 12){
    if(1<=right && right<=12) cout << "AMBIGUOUS" << endl;
    else cout << "MMYY" << endl;
  }else {
    if(1<=right && right<=12) cout << "YYMM" << endl;
    else cout << "NA" << endl;
  }
}