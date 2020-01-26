import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int h = sc.nextInt();
    int a = sc.nextInt();
    int count = 0;
    while (true) {
      h -= a;
      count++;
      if (h <= 0) {
        break;
      }
    }
    System.out.println(count);
  }
}