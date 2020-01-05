import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    Map<String, Integer> map = new HashMap<>();
    int n = sc.nextInt();
    for (int i = 0; i < n; i++) {
      int v;
      String str = sc.next();
      if (map.containsKey(str)) {
        v = map.get(str) + 1;
      } else {
        v = 1;
      }
      map.put(str, v);
    }
    int max = 0;
    String leader = "";
    for (Map.Entry<String, Integer> entry : map.entrySet()) {
      String key = entry.getKey();
      int value = entry.getValue();
      if (value > max) {
        leader = key;
        max = value;
      }
    }
    System.out.println(leader);
  }
}