import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    char[] str = s.toCharArray();
    int count = 1;
    for (int i = 0; i < str.length; i++) {
      if (i + 1 != str.length && str[i] == str[i + 1]) {
        count++;
      } else {
        System.out.print(str[i]);
        System.out.print(count);
        count = 1;
      }
    }
    System.out.println();
  }
}
