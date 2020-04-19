import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int h = 0;
    int m = 0;
    int s = 0;
    if(n >= 3600){
      h = n / 3600;
      n = n - 3600 * h;
    }
    if(n >= 60){
      m = n / 60;
      n = n - 60 * m;
    }
    s = n;
    System.out.println(String.format("%02d", h) + ":" + String.format("%02d", m) + ":" + String.format("%02d", s));
  }
}