#include <iostream>
#include <algorithm>
#include <math.h>
#define LEN 10005

typedef struct pp
{
  char name[100];
  int t;
}P;
using namespace std;
int head, tail, n;
P Q[LEN + 1];

void enqueue(P x) {
  Q[tail] = x;
  tail = (tail + 1) % LEN;
}

P dequeue() {
  P x = Q[head];
  head = (head + 1) % LEN;
  return x;
}

int main(){
  int elaps = 0, c;
  int i, q;
  P u;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++){
    scanf("%s", Q[i].name);
    scanf("%d", &Q[i].t);
  }
  head = 1;
  tail = n + 1;
  while(head != tail){
    u = dequeue();
    c = min(q, u.t);
    u.t -= c;
    elaps += c;
    if(u.t > 0) enqueue(u);
    else {
      printf("%s %d\n", u.name, elaps);
    }
  }
  return 0;
}
