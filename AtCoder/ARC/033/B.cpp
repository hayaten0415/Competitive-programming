#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int na, nb;
  cin >> na >> nb;
  int sum = na + nb;
  int common = 0;
  set<int> a, b;
  rep(i,na) {
    int a_num;
    cin >> a_num;
    a.insert(a_num);
  }
  rep(i, nb){
    int b_num;
    cin >> b_num;
    b.insert(b_num);
  }
  if(na < nb){
    for(auto k: a){
      auto it = b.find(k);
      if(it != b.end()) common++;
    }
  }else {
    for(auto k : b){
      auto it = a.find(k);
      if(it != a.end()) common++;
    }
  }
  double ans = (double)common / (sum - common);
  printf("%.10f\n", ans);
}