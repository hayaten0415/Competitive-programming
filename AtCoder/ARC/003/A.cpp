#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  rep(i,n){
    cin >> a[i];
    reverse(a[i].begin(), a[i].end());
  }
  sort(a.begin(), a.end());
  rep(i,n){
    reverse(a[i].begin(), a[i].end());
    cout << a[i] << endl;
  }
}