import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int x = sc.nextInt();
    int y=sc.nextInt();
    int z=sc.nextInt();
    for(int i=0;i<100;i++){
      if(n==x||n==y||n==z)n=n;
      else {
        if((n-3)!=x&&(n-3)!=y&&(n-3)!=z)n-=3;
        else if((n-2)!=x&&(n-2)!=y&&(n-2)!=z)n-=2;
        else if((n-1)!=x&&(n-1)!=y&&(n-1)!=z)n--;
      }
    }
    System.out.println((n<=0)?"YES":"NO");
  }
}