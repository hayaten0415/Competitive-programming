import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    double m = sc.nextDouble();
    sc.close();
    int VV = (int)m / 100;
    if (VV < 1) {
      System.out.println("00");
    } else if (1 <= VV && VV <= 50) {
      if (VV < 10) {
        System.out.println(String.format("%02d", VV));
      } else {
        System.out.println(VV);
      }
    } else if (60 <= VV && VV <= 300) {
      System.out.println(VV / 10 + 50);
    } else if ((350 <= VV && VV < 700) || m == 70000) {
      System.out.println((((VV/ 10) - 30) / 5) + 80);
    } else {
      System.out.println("89");
    }
  }
}