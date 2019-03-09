import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        long[] a = new long[n];
        int[] b = new int[n];
        long ans = 0;
        int anscount = 0;
        for(int i =0; i < n; i++){
            a[i] = sc.nextLong();
            b[i] = sc.nextInt();
        }
		for(int k = 0; k < n - 1; k++) { 
            int pos = k;
            for (int j = k + 1; k < n; j++) {
                if (a[j] < a[pos]) {
                    pos = j;
                }
            }
            long w = a[k];
            int y = b[k];
            a[k] = a[pos];
            a[pos] = w;
            b[k] = b[pos];
            b[pos] = y;

        }
        for(int d = 0; d < n; d++){
            if(anscount == m){
                break;
            }else{
                for(int e = 0; e < b[d]; e++){
                    anscount = anscount + 1;
                    ans = ans + a[d];
                    if(anscount == m){
                            break;
                    } 
                }
            }
        }
        System.out.println(ans);

    }
}