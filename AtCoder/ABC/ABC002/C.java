import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int xa = sc.nextInt();
    int ya = sc.nextInt();
    int xb = sc.nextInt();
    int yb = sc.nextInt();
    int xc = sc.nextInt();
    int yc = sc.nextInt();
    double ans = (double)Math.abs((xb - xa) * (yc - ya) - (yb - ya) * (xc - xa)) / 2;
    System.out.println(ans);
  }
}