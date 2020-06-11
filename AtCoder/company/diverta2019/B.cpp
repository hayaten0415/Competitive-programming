#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int R, G, B, N;
  ll ans = 0;
  cin >> R >> G >> B >> N;
  for (int r = 0; r * R <= N; r++){
    for (int g = 0; r * R + g * G <= N; g++){
      if((N - (r * R + g * G)) % B == 0)ans++;
    }
  }
  cout << ans << endl;
}