#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;
int n;
ll x;

ll ans(int n, ll x){
  if(n == 0) return 1;
  ll len = (1LL << (n + 1)) - 3;
  ll num = (1LL << (n)) - 1;
  if(x == 1) return 0;
  //1つ分のバーガーの途中で終わっている場合
  else if(x <= len + 1) return ans(n -1, x -1);
  //ちょうど半分の位置にあるpのところまでの場合
  else if(x == len + 2) return num + 1;
  //一つ分のL-1バーガーを完全に含み、もう一つのL -1バーガーの途中まで含む場合。
  else if (x <= (len + 1) * 2) return num + 1 + ans(n-1, x-len-2);
  //全て含む
  else return num * 2 + 1;

}

int main() {
  int n;
  ll x;
  cin >> n >> x;
  ll ansa = ans(n, x);
  cout << ansa << endl;
}