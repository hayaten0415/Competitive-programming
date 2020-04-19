import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.next();
    char[] str = s.toCharArray();
    int n = sc.nextInt();
    int l;
    int r;
    for (int i = 0; i < n; i++) {
      l = sc.nextInt();
      r = sc.nextInt();
      l--;
      r--;
      reverse(str, l, r);
    }
    s = new String(str);
    System.out.println(s);
  }
  
  private static void swap(char[] nums, int i, int l) {
    char temp = nums[i];
    nums[i] = nums[l];
    nums[l] = temp;
  }
  
  private static void reverse(char[] nums, int start, int end) {
    int i = start;
    int l = end;
    while (i < l) {
      swap(nums, i, l);
      i++;
      l--;
    }
  }
}
