import java.util.*;
import java.util.concurrent.locks.Condition;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    AC ac = new AC();

    int n = sc.nextInt();
    int a[] = new int[n];
    int answer = 0;
    for (int i = 0; i < n; i++) {
      a[i] = sc.nextInt();
    }
    for (int i = 0; i < n; i++) {
      answer = answer + ac.ans(a[i]);
    }
    System.out.println(answer);
  }


  static class AC {
    int count = 0;
    int ans(int a){
      if(a % 2 == 0 || a % 3 == 2){
        count++;
        ans(a - 1);
      }
      return count;
    }   
  }
}
