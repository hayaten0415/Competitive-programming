import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int q = sc.nextInt();
    boolean condition = false;
    if (q == 1)
      condition = true;
    System.out.println(condition ? "ABC" : "chokudai");
  }
}
