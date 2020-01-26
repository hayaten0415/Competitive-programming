import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String N[][] = new String[4][4];
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < N.length; j++) {
        N[3 - i][3 - j] = sc.next();
      }
    }
    for (int i = 0; i < N.length; i++) {
      System.out.println(String.join(" ", N[i]));
    }
  }
}