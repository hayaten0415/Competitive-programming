import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    String t = sc.next();
    boolean condition = true;
    for (int i = 0; i < s.length(); i++) {
      if ((s.charAt(i) == t.charAt(i))
          || ((s.charAt(i) == 'a' || s.charAt(i) == 't' || s.charAt(i) == 'c' || s.charAt(i) == 'o'
              || s.charAt(i) == 'd' || s.charAt(i) == 'e' || s.charAt(i) == 'r') && t.charAt(i) == '@')
          || (t.charAt(i) == 'a' || t.charAt(i) == 't' || t.charAt(i) == 'c' || t.charAt(i) == 'o' || t.charAt(i) == 'd'
              || t.charAt(i) == 'e' || t.charAt(i) == 'r') && s.charAt(i) == '@') {
        continue;
      } else {
        condition = false;
        break;
      }
    }
    if (condition) {
      System.out.println("You can win");
    } else {
      System.out.println("You will lose");
    }
  }
}
