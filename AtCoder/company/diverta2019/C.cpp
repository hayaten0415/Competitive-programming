#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  int a_count = 0;
  int b_count = 0;
  int ab_count = 0;
  vector<int> a(n, 0);
  vector<int> b(n, 0);
  cin >> n;
  rep(i,n){
    string s;
    cin >> s;
    if(s[0] == 'B'){
      b_count++;
      b[i] = 1;
    }
    if(s[s.size() -1] == 'A'){
      a_count++;
      a[i] = 1;
    }
    rep(j,s.size() -1){
      if(s[j] == 'A'&& s[j+1] == 'B')ab_count++;
    }
  }
  if(a == b && a_count > 0){
    cout << a_count + ab_count - 1 << endl;
    return 0;
  }
  cout << min(a_count, b_count) + ab_count << endl;
}