#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  int ans_index = 0;
  int sum = 0;
  for (int i = 1; i <= n; i++){
    sum += i;
    if(sum >= n){
      ans_index = i;
      break;
    }
  }
  int non_num = sum - n;
  for (int i = 1; i <= ans_index; i++){
    if(i != non_num){
      cout << i << (i == ans_index ? "\n" : " ");
    }
  }
}