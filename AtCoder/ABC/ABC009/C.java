import java.util.*;
import java.io.*;

public class C {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int k = sc.nextInt();
    String string = sc.next();
    int changeCount = 0;
    sc.close();
    char permutation[] = new char[n];
    char minpermutation[] = new char[n];
    for (int i = 0; i < n; i++) {
      permutation[i] = string.charAt(i);
      minpermutation[i] = string.charAt(i);
    }
    Arrays.sort(minpermutation);
    for (int i = 0; i < n; i++) {
      if (changeCount <= k) {
        for (int j = 0; j < n; j++) {
          if (minpermutation[i] == permutation[j]) {
            if (i != j && changeCount + 2 <= k) {
              changeCount += 2;
              swap(i, j, permutation);
            } else {
              break;
            }
          }
        }
      } else {
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      System.out.print(permutation[i]);
    }
  }
  private static void swap(int i, int j, char[] array) {
    char temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
}