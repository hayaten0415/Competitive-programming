#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int k;
  bool cond = true;
  vector<int> a(5);
  rep(i, 5) cin >> a[i];
  cin >> k;
  rep(i,4){
    for (int j = i + 1; j < 5;j++){
      if(a[j]- a[i] > k) {
        cond = false;
        break;
      }
    }
  }
  cout << (cond? "Yay!" : ":(") << endl;
}