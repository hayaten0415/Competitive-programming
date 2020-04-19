import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    AC ac = new AC();
    boolean ans = false;
    int txa = sc.nextInt();
    int tya = sc.nextInt();
    int txb = sc.nextInt();
    int tyb = sc.nextInt();
    int T = sc.nextInt();
    int V = sc.nextInt();
    int n = sc.nextInt();
    int[] x = new int[n];
    int[] y = new int[n];    
    for (int i = 0; i < n; i++) {
      x[i] = sc.nextInt();
      y[i] = sc.nextInt();
    }
    ans = ac.ans(txa, tya, txb, tyb, x, y, n, T, V);
    if(ans){
      System.out.println("YES");
    }else{
      System.out.println("NO");
    }
  }
  static class AC {
    boolean ans = false;
    double distance = 999999;
    boolean ans(int xa, int ya, int xb, int yb, int[] x, int[] y, int n, int t, int v){
      for(int i = 0; i < n; i++){
        distance = Math.sqrt(Math.pow(Math.abs(x[i] - xa), 2) + Math.pow(Math.abs(y[i] - ya), 2)) +  Math.sqrt(Math.pow(Math.abs(xb - x[i]), 2) + Math.pow(Math.abs(yb - y[i]), 2));
        if(distance <= t * v){
          ans = true;
          break;
        }
      }
      return ans;
    }   
  }
}
