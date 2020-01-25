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
          || ("atcoder".indexOf(s.charAt(i)) >= 0 && t.charAt(i) == '@')
          || ("atcoder".indexOf(t.charAt(i)) >= 0 && s.charAt(i) == '@')) {
        continue;
      } else {
        condition = false;
        break;
      }
    }
    System.out.println(condition? "You can win" : "You will lose");
  }
}
