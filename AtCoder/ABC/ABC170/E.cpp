#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, q;
  cin >> n >> q;
  //各幼稚園最大レートの集合
  multiset<int> maxs;
  //各幼稚園にいる園児のレートの集合
  vector<multiset<int>> A(200000);
  //園児iのレート
  vector<int> rates(n);
  //園児iが所属する幼稚園
  vector<int> belong(n);
  rep(i, n){
    int a, b;
    cin >> a >> b;
    b--;
    rates[i] = a;
    belong[i] = b;
    if(A[b].empty()){
      maxs.insert(a);
    }else{
      int maxnow = *A[b].rbegin();
      if(maxnow < a){
        maxs.erase(maxs.find(maxnow));
        maxs.insert(a);
      }
    }
    A[b].insert(a);
  }
  rep(i, q){
    int c, d;
    cin >> c >> d;
    c--;
    d--;
    int maxnow = *A[belong[c]].rbegin();
    A[belong[c]].erase(A[belong[c]].find(rates[c]));
    if(maxnow == rates[c]){
      maxs.erase(maxs.find(rates[c]));
      if(!A[belong[c]].empty()){
        int nextmaxnow = *A[belong[c]].rbegin();
        maxs.insert(nextmaxnow);
      }
    }
    belong[c] = d;
    if(A[belong[c]].empty()){
      maxs.insert(rates[c]);
    }else {
      int maxnow = *A[belong[c]].rbegin();
      if(maxnow < rates[c]){
        maxs.erase(maxs.find(maxnow));
        maxs.insert(rates[c]);
      }
    }
    A[belong[c]].insert(rates[c]);
    cout << *maxs.begin() << endl;
  }
}