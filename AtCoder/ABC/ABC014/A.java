import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int m = a % b;
    if(m == 0){
      System.out.println("0");
    }else{
      System.out.println(Math.abs(b - m));
    }
    System.out.println(Math.abs(b - m));
  }
}