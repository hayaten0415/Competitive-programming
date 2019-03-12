import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {
        try(BufferedReader input = new BufferedReader(new InputStreamReader(System.in))){
 
			String[] l1 = input.readLine().split(" ");
			int N = Integer.parseInt(l1[0]);
			int M = Integer.parseInt(l1[1]);
            int C = Integer.parseInt(l1[2]);

            String[] l2 = input.readLine().split(" ");
            int[] B = new int[M];
            for (int i = 0; i < M; i++) {
                B[i] = Integer.parseInt(l2[i]);
            }

            int[][] data = new int[N][M];
            int cnt = 0;

            for (int i = 0; i < N; i++) {
                    int calc = 0;
                    String[] lines = input.readLine().split(" ");
                    for (int j = 0; j < M; j++) {
                        calc += Integer.parseInt(lines[j]) * B[j];
                    }
                    if (calc + C > 0)
                        cnt++;
            }

                System.out.println(cnt);
        }catch(IOException e){
            e.printStackTrace();
        }
    }
}