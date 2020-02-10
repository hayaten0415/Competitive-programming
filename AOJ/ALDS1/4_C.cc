#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define NUM 1236571
#define L 14
using namespace std;
using ll = long long;

char H[NUM][L];

//文字から数字に変換
int getChar(char ch) {
  if(ch == 'A') return 1;
  else if(ch == 'C') return 2;
  else if(ch == 'G') return 3;
  else if(ch == 'T') return 4;
  else return 0;
}

ll getKey(char str[]) {
  ll sum = 00, p = 1, i;
  for (i = 0; i < strlen(str); i++) {
    sum += p * (getChar(str[i]));
    p *= 5;
  }
  return sum;
}
int h1(int key) {
  return key % NUM;
}

int h2(int key) {
  return 1 + (key % (NUM - 1));
}

int find(char str[]){
  ll key, i, h;
  key = getKey(str);
  for (i = 0;;i++){
    h = (h1(key) + i * h2(key)) % NUM;
    if( strcmp(H[h], str) == 0) return 1;
    else if(strlen(H[h]) == 0) return 0;
  }
  return 0;
}

int insert(char str[]) {
  ll key, i, h;
  key = getKey(str); //文字列を数字に変換
  for (i = 0;; i++) {
    h = (h1(key) + i * h2(key)) % NUM;
    if( strcmp(H[h], str) == 0) return 1;
    else if(strlen(H[h]) == 0) {
      strcpy(H[h], str);
      return 0;
    }
  }
  return 0;
}

int main() {
  int i, n, h;
  char str[L], com[9];
  for (i = 0; i < NUM; i++) H[i][0] = '\0';
  scanf("%d", &n);
  for (i = 0; i < n; i++){
    scanf("%s %s", com, str);
    if(com[0] == 'i'){
      insert(str);
    } else {
      if(find(str)){
        printf("yes\n");
      } else {
        printf("no\n");
      }
    }
  }
  return 0;
}

