import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String n = sc.next();
    char[] c = n.toCharArray();
    for (int i = 0; i < c.length; i++) {
      if(i == 0){
        c[i] = Character.toUpperCase(c[i]);
      }else{
        c[i] = Character.toLowerCase(c[i]);
      }
    }
    System.out.println(c);
  }
}