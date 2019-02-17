import java.util.Scanner;

public class B {
    public static void main(String[]args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int t = sc.nextInt();

        int[] c = new int[n];
        int[] time = new int[n];

        for(int i = 0; i < n; i++){
            c[i] = sc.nextInt();
            time[i] = sc.nextInt();
        }

        int answer = 1001;

        for(int i = 0; i < n; i++){
            if(time[i] <= t){
                answer = Math.min(answer, c[i]);
            }
        }
        if(answer != 1001){
            System.out.println(answer);
        }else{
            System.out.println("TLE");
        }
    }
}