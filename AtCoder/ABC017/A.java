import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int ans = 0;
    for (int i = 0; i < 3; i++) {
      int s = sc.nextInt();
      int e = sc.nextInt();
      ans += s * e;
    }
    System.out.println(ans / 10);
  }
}
