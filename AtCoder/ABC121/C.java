import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        long[][] a = new long[n][2];
        int number = 0;
        long ans = 0;
        for(int i =0; i < n; i++){
            a[i][0] = sc.nextLong();
            a[i][1] = sc.nextLong();
        }
        //ここまで値を格納するフェーズ
        //値段の安い順を考慮して並べ替えるが、値段が重複してる部分を消さないようにする
        Arrays.sort(a,(x,y)->Long.compare(x[0], y[0]));
        //安い店から買っていく処理        
        for(int i = 0; i < n; i++){
            if(number + a[i][1] < m){
                ans += a[i][0] * a[i][1];
			    number += a[i][1];
            }else{
                ans += a[i][0] * (m - number);
				break;
            }
        }
        System.out.println(ans);
    }
}