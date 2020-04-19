import java.util.HashMap;
import java.util.Scanner;

public class D {
  public static void main(String[] args) {
    HashMap<Integer, Integer> ans = new HashMap<>();
    int INF = (int) 1e9 + 1;
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int condition_point = 0;
    int answer = 0;
    int[] nums = new int[n];
    for (int i = 0; i < n; i++) {
      nums[i] = sc.nextInt();
      if (i == 0) {
        ans.put(i, nums[0]);
      }
      if (ans.get(condition_point) == condition_point + 1) {
        condition_point++;
      }
      //二分探索の下限
      int lower = condition_point;
      //二分探索の上限
      int upper = ans.size() - 1;
      while (lower < upper) {
        int mid = (lower + upper) / 2;
        if (ans.get(mid) < nums[i]) {
          if (lower == mid) {
            if (ans.get(lower) > nums[i]) {
              ans.put(mid, nums[i]);
              break;
            } else {
              ans.put(upper, nums[i]);
              break;
            }
          }
          lower = mid + 1;
        } else {
          if (lower == mid) {
            if (ans.get(lower) > nums[i]) {
              ans.put(lower, nums[i]);
              break;
            } else {
              ans.put(upper, nums[i]);
              break;
            }
          }
          upper = mid - 1;
        }
      }
      if (ans.get(ans.size() - 1) <= nums[i]) {
        ans.put(ans.size(), INF);
      }
    }
    if (ans.get(ans.size() - 1) == INF) {
      answer = ans.size() - 1;
    }
    System.out.println(n - answer);
  }
}


