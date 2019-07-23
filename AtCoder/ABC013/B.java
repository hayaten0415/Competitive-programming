import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int diff = Math.abs(a - b);
    if(diff <= 5){
      System.out.println(diff);
    }else{
      System.out.println(10 - diff);
    }
  }
}