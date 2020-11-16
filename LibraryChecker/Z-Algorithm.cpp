#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

vector<int> Zalgo(string str){
  int n = str.size();
  vector<int> A(n, 0);
  int from = -1;
  int last = -1;
  for (int i = 1; i < n; i++){
    int &same = A[i];
    if(from != -1){
      same = min(A[i] - from, last - i);
      same = max(0, same);
    }
    while(i + same < n && str[same] == str[i+same])same++;
    if(last < i + same){
      last = i + same;
      from = i;
    }
  }
  A[0] = n;
  return A;
}

int main() {
  string s;
  cin >> s;
  auto A = Zalgo(s);
  for (auto k : A)cout << k << " ";cout << "\n";
}