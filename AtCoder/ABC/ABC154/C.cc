#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  cout << (a.size() == n ? "YES" : "NO") << endl;
}
