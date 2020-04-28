#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<P> a(n);
  rep(i,n){
    int b;
    cin >> b;
    a[i] = make_pair(-b, i + 1);
  }
  sort(a.begin(), a.end());
  rep(i,n){
    cout << a[i].second << endl;
  }
}