import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int tmp = 0;
    ArrayList<Integer> ans1 = new ArrayList<Integer>();
    ArrayList<Integer> maxcount = new ArrayList<Integer>();
    int count = 0;
    for (int i = 0; i < n; i++) {
      ans1.add(sc.nextInt());
    }
    int ans = Collections.max(ans1);
    for(int i = 0; i < n; i++){
      if (ans == ans1.get(i)) {
        count++;
        maxcount.add(i);
      }
    }
    for(int i = 0; i < n; i++){
      if(count >= 2){
        System.out.println(ans);
      }else{
        if(i == maxcount.get(0)){
          ans1.remove(i);
          tmp = Collections.max(ans1);
          System.out.println(tmp);
          ans1.add(i, ans); 
        }else{
          System.out.println(ans);
        }
      }
    }
  }
}