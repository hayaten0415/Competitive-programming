#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  int a, b;
  cin >> n;
  ll sum = 0;
  bool cond = true;
  vector<P> tasks;
  rep(i ,n){
    cin >> a >> b;
    tasks.emplace_back(b, a);
  }
  sort(tasks.begin(), tasks.end());
  for(auto v: tasks){
    sum += v.second;
    if(sum > v.first){
      cond = false;
      break;
    }
  }
  cout << (cond ? "Yes" : "No") << endl;
  return 0;
}