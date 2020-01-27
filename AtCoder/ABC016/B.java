import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int c = sc.nextInt();
    boolean plus = false;
    boolean minus = false;
    if (a + b == c) {
      plus = true;
    }
    if (a - b == c) {
      minus = true;
    }
    if (plus && minus) {
      System.out.println("?");
    } else if (plus && !minus) {
      System.out.println("+");
    } else if (!plus && minus) {
      System.out.println("-");
    } else {
      System.out.println("!");
    }
  }
}
