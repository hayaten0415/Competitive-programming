#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;


int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<string> a(n + 2, "");
  a[0] = "S", a[n] = "S";
  a[1] = "S", a[n+1] = "S";
  bool cond1 = true;
  for (int i = 1; i <= n-2; i++){
    if(s[i-1] == 'o' && a[i] == "S" && a[i-1] == "S"){
      a[i + 1] = "S";
    }else if(s[i-1] == 'o' && a[i] == "S" && a[i-1] == "W"){
      a[i + 1] = "W";
    }else if(s[i-1] == 'o' && a[i] == "W" && a[i-1] == "S"){
      a[i + 1] = "W";
    }else if(s[i-1] == 'o' && a[i] == "W" && a[i-1] == "W"){
      a[i + 1] = "S";
    }else if(s[i-1] == 'x' && a[i] == "S" && a[i-1] == "S"){
      a[i + 1] = "W";
    }else if(s[i-1] == 'x' && a[i] == "S" && a[i-1] == "W"){
      a[i + 1] = "S";
    }else if(s[i-1] == 'x' && a[i] == "W" && a[i-1] == "S"){
      a[i + 1] = "S";
    }else if(s[i -1] ==  'x' && a[i] == "W" && a[i-1] == "W"){
      a[i + 1] = "W";
    }
  }
  for(int i = 1; i <= n; i++){
    if(a[i] == "S"){
      if(s[i-1] == 'o'){
        if(a[i-1] != a[i+1]){
          cond1 = false;
          break;
        }
      }else{
        if(a[i-1] == a[i+1]){
          cond1 = false;
          break;
        }
      }
    }else{
      if(s[i-1] == 'o'){
        if(a[i-1] == a[i+1]){
          cond1 = false;
          break;
        }
      }else{
        if (a[i - 1] != a[i+1]){
          cond1 = false;
          break;
        }
      }
    }
  }
  if(cond1){
    for (int i = 1; i <= n; i++){
      cout << a[i];
    }
    return 0;
  }
  a.clear();
  a.assign(n + 2, "");
  a[0] = "S", a[n] = "S";
  a[1] = "W", a[n + 1] = "W";
  bool cond2 = true;
  for (int i = 1; i <= n-2; i++){
    if(s[i-1] == 'o' && a[i] == "S" && a[i-1] == "S"){
      a[i + 1] = "S";
    }else if(s[i-1] == 'o' && a[i] == "S" && a[i-1] == "W"){
      a[i + 1] = "W";
    }else if(s[i-1] == 'o' && a[i] == "W" && a[i-1] == "S"){
      a[i + 1] = "W";
    }else if(s[i-1] == 'o' && a[i] == "W" && a[i-1] == "W"){
      a[i + 1] = "S";
    }else if(s[i-1] == 'x' && a[i] == "S" && a[i-1] == "S"){
      a[i + 1] = "W";
    }else if(s[i-1] == 'x' && a[i] == "S" && a[i-1] == "W"){
      a[i + 1] = "S";
    }else if(s[i-1] == 'x' && a[i] == "W" && a[i-1] == "S"){
      a[i + 1] = "S";
    }else if(s[i -1] ==  'x' && a[i] == "W" && a[i-1] == "W"){
      a[i + 1] = "W";
    }
  }
  for(int i = 1; i <= n; i++){
    if(a[i] == "S"){
      if(s[i-1] == 'o'){
        if(a[i-1] != a[i+1]){
          cond2 = false;
          break;
        }
      }else{
        if(a[i-1] == a[i+1]){
          cond2 = false;
          break;
        }
      }
    }else{
      if(s[i-1] == 'o'){
        if(a[i-1] == a[i+1]){
          cond2 = false;
          break;
        }
      }else{
        if (a[i - 1] != a[i+1]){
          cond2 = false;
          break;
        }
      }
    }
  }
  if(cond2){
    for (int i = 1; i <= n; i++){
      cout << a[i];
    }
    return 0;
  }
  a.clear();
  a.assign(n + 2, "");
  a[0] = "W", a[n] = "W";
  a[1] = "W", a[n + 1] = "W";
  bool cond3 = true;
  for (int i = 1; i <= n-2; i++){
    if(s[i-1] == 'o' && a[i] == "S" && a[i-1] == "S"){
      a[i + 1] = "S";
    }else if(s[i-1] == 'o' && a[i] == "S" && a[i-1] == "W"){
      a[i + 1] = "W";
    }else if(s[i-1] == 'o' && a[i] == "W" && a[i-1] == "S"){
      a[i + 1] = "W";
    }else if(s[i-1] == 'o' && a[i] == "W" && a[i-1] == "W"){
      a[i + 1] = "S";
    }else if(s[i-1] == 'x' && a[i] == "S" && a[i-1] == "S"){
      a[i + 1] = "W";
    }else if(s[i-1] == 'x' && a[i] == "S" && a[i-1] == "W"){
      a[i + 1] = "S";
    }else if(s[i-1] == 'x' && a[i] == "W" && a[i-1] == "S"){
      a[i + 1] = "S";
    }else if(s[i -1] ==  'x' && a[i] == "W" && a[i-1] == "W"){
      a[i + 1] = "W";
    }
  }
  for(int i = 1; i <= n; i++){
    if(a[i] == "S"){
      if(s[i-1] == 'o'){
        if(a[i-1] != a[i+1]){
          cond3 = false;
          break;
        }
      }else{
        if(a[i-1] == a[i+1]){
          cond3 = false;
          break;
        }
      }
    }else{
      if(s[i-1] == 'o'){
        if(a[i-1] == a[i+1]){
          cond3 = false;
          break;
        }
      }else{
        if(a[i - 1] != a[i+1]){
          cond3 = false;
          break;
        }
      }
    }
  }
  if(cond3){
    for (int i = 1; i <= n; i++){
      cout << a[i];
    }
    return 0;
  }
  a.clear();
  a.assign(n + 2, "");
  a[0] = "W", a[n] = "W";
  a[1] = "S", a[n + 1] = "S";
  bool cond4 = true;
  for (int i = 1; i <= n-2; i++){
    if(s[i-1] == 'o' && a[i] == "S" && a[i-1] == "S"){
      a[i + 1] = "S";
    }else if(s[i-1] == 'o' && a[i] == "S" && a[i-1] == "W"){
      a[i + 1] = "W";
    }else if(s[i-1] == 'o' && a[i] == "W" && a[i-1] == "S"){
      a[i + 1] = "W";
    }else if(s[i-1] == 'o' && a[i] == "W" && a[i-1] == "W"){
      a[i + 1] = "S";
    }else if(s[i-1] == 'x' && a[i] == "S" && a[i-1] == "S"){
      a[i + 1] = "W";
    }else if(s[i-1] == 'x' && a[i] == "S" && a[i-1] == "W"){
      a[i + 1] = "S";
    }else if(s[i-1] == 'x' && a[i] == "W" && a[i-1] == "S"){
      a[i + 1] = "S";
    }else if(s[i -1] ==  'x' && a[i] == "W" && a[i-1] == "W"){
      a[i + 1] = "W";
    }
  }
  for(int i = 1; i <= n; i++){
    if(a[i] == "S"){
      if(s[i-1] == 'o'){
        if(a[i-1] != a[i+1]){
          cond4 = false;
          break;
        }
      }else{
        if(a[i-1] == a[i+1]){
          cond4 = false;
          break;
        }
      }
    }else{
      if(s[i-1] == 'o'){
        if(a[i-1] == a[i+1]){
          cond4 = false;
          break;
        }
      }else{
        if (a[i - 1] != a[i+1]){
          cond4 = false;
          break;
        }
      }
    }
  }
  if(cond4){
    for (int i = 1; i <= n; i++){
      cout << a[i];
    }
    return 0;
  }
  cout << -1 << endl;
}