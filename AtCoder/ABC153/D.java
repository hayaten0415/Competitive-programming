import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long h = sc.nextLong();
    double value = Math.log(h) / Math.log(2.0);
    int pow = (int) value + 1;
    long ans = (long)Math.pow(2, (double)pow) - (long)1;
    System.out.println(ans);
  }
}