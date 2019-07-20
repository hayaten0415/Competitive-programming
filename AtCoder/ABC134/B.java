import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int d = sc.nextInt();
    int ans = 0;
    int able = 2 * d + 1;
    for(int i = 1; i < 20; i++){
      if (i * able >= n) {
        ans = i;
        break;
      }
    }
    System.out.println(ans);
  }
}