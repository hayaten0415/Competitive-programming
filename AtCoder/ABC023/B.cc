#include <iostream>
#include <algorithm>
using namespace std;


int remainder1mod3(int n, string s) {
  for (int i = 0; i < n; i++){
    if (i % 3 == 0){
      if (s.at(i) == 'b'){
        continue;
      }else {
        return -1;
      }
    } else if(i % 3 == 1) {
      if(s.at(i) == 'c') {
        continue;
      } else {
        return -1;
      }
    } else {
      if(s.at(i) == 'a') {
        continue;
      } else {
        return -1;
      }
    }
  }
  return n / 2;
}

int remainder2mod3(int n, string s) {
  for (int i = 0; i < n; i++)
  {
    if (i % 3 == 0){
      if (s.at(i) == 'c'){
        continue;
      }else {
        return -1;
      }
    } else if(i % 3 == 1) {
      if(s.at(i) == 'a') {
        continue;
      } else {
        return -1;
      }
    } else {
      if(s.at(i) == 'b') {
        continue;
      } else {
        return -1;
      }
    }
  }
  return n / 2;
}

int remainder0mod3(int n, string s) {
  for (int i = 0; i < n; i++){
    if (i % 3 == 0){
      if (s.at(i) == 'a'){
        continue;
      }else {
        return -1;
      }
    } else if(i % 3 == 1) {
      if(s.at(i) == 'b') {
        continue;
      } else {
        return -1;
      }
    } else {
      if(s.at(i) == 'c') {
        continue;
      } else {
        return -1;
      }
    }
  }
  return n / 2;
}



int main()
{
  int n, ans;
  string s;
  cin >> n >> s;
  if(n % 3 == 1) ans = remainder1mod3(n, s);
  if(n % 3 == 2) ans = remainder2mod3(n, s);
  if(n % 3 == 0) ans = remainder0mod3(n, s);
  if (n % 2 == 0) ans = -1;
  cout << ans << endl;
  return 0;
}