#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  string mx;
  int maxi;
  cin >> mx >> maxi;
  int sum = maxi;
  rep(i, n-1) {
    int num;
    string str;
    cin >> str >> num;
    sum += num;
    if(num > maxi){
      maxi = num;
      mx = str;
    }
  }
  if(maxi > sum / 2){
    cout << mx << endl;
  }else {
    cout << "atcoder" << endl;
  }
}