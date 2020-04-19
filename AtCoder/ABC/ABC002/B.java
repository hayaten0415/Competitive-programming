import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String str = sc.next();
    char[] string = new char[str.length()];
    for (int i = 0; i < string.length; i++) {
      string[i] = str.charAt(i);
      if (string[i] != 'a' && string[i] != 'i' && string[i] != 'u' && string[i] != 'e' && string[i] != 'o') {
        System.out.print(string[i]);
      }
      if (i == string.length - 1) {
        System.out.print("\n");
      }
    }
  }
}