import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String n = sc.next();
    char[] str = new char[n.length()];
    for (int i = 0; i < str.length; i++) {
      str[i] = n.charAt(i);
    }
    if (str[0] == 'a' && str.length == 1) {
      System.out.println("-1");
    } else {
      System.out.println("a");
    }
  }
}