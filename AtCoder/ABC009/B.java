import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int second_index = n - 2;
    int[] prices = new int[n];
    for (int i = 0; i < n; i++) {
      prices[i] = sc.nextInt();
    }
    sc.close();
    Arrays.sort(prices);
    for (int i = n - 2; i >= 0 ; i--) {
      if (prices[i] != prices[n - 1]) {
        second_index = i;
        break;
      }
    }
    System.out.println(prices[second_index]);
  }
}