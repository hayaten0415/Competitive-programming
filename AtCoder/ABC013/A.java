import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    char[] n = s.toCharArray();
    if (n[0] == 'A') {
      System.out.println("1");
    } else if (n[0] == 'B') {
      System.out.println("2");
    } else if (n[0] == 'C') {
      System.out.println("3");
    } else if (n[0] == 'D') {
      System.out.println("4");
    } else {
      System.out.println("5");
    }
  }
}