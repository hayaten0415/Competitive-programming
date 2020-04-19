import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        AC ac = new AC();
        int N = sc.nextInt();
        int Q = sc.nextInt();
        int answer = 0;
        int c;
        int d;
        String S = sc.next();
        int l[] = new int[Q];
        int r[] = new int[Q];
        for (int i = 0; i < Q; i++) {
            l[i] = sc.nextInt();
            r[i] = sc.nextInt();
        }
        for (int i = 0; i < Q; i++) {
            c = l[i]; 
            d = r[i];
            answer = AC.ans(c, d, S);
          System.out.println(answer);
        }
    }
    static class AC{
            int ans(int a, int b, String str){
                int count = 0;
                boolean f;
                for(int i = a - 1; i < b; i++){
                    if(str.charAt(i) == 'A'){
                        f = true;
                    }else if( i != a - 1 && f && str.charAt(i) == 'C'){
                        count++;
                    }else{
                        f = false;
                    }
                }
                return count;
            }
    }
}