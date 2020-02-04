#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>


using namespace std;

struct Node {
  int key;
  Node *prev, *next;
};

Node *nil;

void init() {
  nil = (Node *)malloc(sizeof(Node));
  nil->next = nil;
  nil->prev = nil;
}

void printList() {
  Node *cur = nil->next;
  int count = 0;
  while(true) {
    if(cur == nil) break;
    if(count++ > 0) cout << " ";
    printf("%d", cur->key);
    cur = cur->next;
  }
  cout << endl;
}

void insert(int key){
  Node *x = (Node *)malloc(sizeof(Node));
  x->key = key;
  // 番兵の直後に要素を追加
  x->next = nil->next;
  nil->next->prev = x;
  nil->next = x;
  x->prev = nil;
}

Node* listSearch(int key) {
  Node *cur = nil->next; //番兵の次の要素から巡る
  while (cur != nil && cur->key != key) {
    cur = cur->next;
  }
  return cur;
}

void deleteNode(Node *t) {
  if( t == nil) return; //tが番兵の場合は処理しない
  t->prev->next = t->next;
  t->next->prev = t->prev;
  free(t);
}

void deleteFirst() {
  deleteNode(nil->next);
}

void deleteLast() {
  deleteNode(nil->prev);
}

void deleteKey(int key){
  deleteNode(listSearch(key));
}

int main()
{
  int key, n;
  scanf("%d", &n);
  char command[30];
  init();
  for (int i = 0; i < n; i++){
    scanf("%s%d", command, &key);
    if(command[0] == 'i') insert(key);
    else if (command[0] == 'd') {
      if(strlen(command) > 6) {
        if(command[6] == 'F') deleteFirst();
        else if(command[6] == 'L') deleteLast();
      } else {
        deleteKey(key);
      }
    }
  }
  printList();
  return 0;
}