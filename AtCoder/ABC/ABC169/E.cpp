#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  rep(i, n) cin >> a[i] >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int L,R;
  if(n%2==1){
    L = a[n/2];
    R = b[n/2];
    cout<<( R-L+1 )<<endl;
  }else{
    L = a[n/2] + a[n/2-1];
    R = b[n/2] + b[n/2-1];
    cout<<( R-L+1 )<<endl;
  }
}