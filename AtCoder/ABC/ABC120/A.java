import java.util.Scanner;

public class Main {
    public static void main(String[]args){
        Scanner sc = new Scanner(System.in);

        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int count = 0;

        for(int i = 0; i < b; i++){
            if (b - a >= 0 && count < c) {
                b = b - a;
                count = count + 1; 
            }
        }

        System.out.println(count);
    }
}