import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int ans1 = n / 2;
    int ans2 = n % 2;
    sc.close();
    System.out.println(ans1 + ans2);
  }
}