import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int num = 2025 - n;
    ArrayList<Integer> ans1 = new ArrayList<Integer>();
    ArrayList<Integer> ans2 = new ArrayList<Integer>();
    for (int i = 1; i <= 9; i++) {
      for (int k = 1; k <= 9; k++) {
        if(num == i * k){
          ans1.add(i);
          ans2.add(k);
        }
      }
    }
    for(int i = 0; i < ans1.size(); i++){
      System.out.println(ans1.get(i) +  " x " + ans2.get(i));
    }
  }
}

