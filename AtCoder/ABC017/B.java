import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    int i = 0;
    boolean condition = true;
    while (i < s.length()) {
      if (s.charAt(i) == 'o' || s.charAt(i) == 'k' || s.charAt(i) == 'u')
        i++;
      else if (s.charAt(i) == 'c' && s.charAt(i + 1) == 'h')
        i += 2;
      else {
        condition = false;
        break;
      }
    }
    System.out.println(condition ? "YES" : "NO");
  }
}
