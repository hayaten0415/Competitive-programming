import java.util.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int a = sc.nextInt();
        int b = sc.nextInt();
        int k = sc.nextInt();
        ArrayList<Integer> aa = new ArrayList<Integer>();
        ArrayList<Integer> bb = new ArrayList<Integer>();
        ArrayList<Integer> kk = new ArrayList<Integer>();

        for (int i = 1; i <= a; i++) {
            if (a % i == 0) {
                aa.add(i);
            }
        }

        for (int c = 1; c <= b; c++) {
            if (b % c == 0) {
                bb.add(c);
            }
        }
        if (aa.size() >= bb.size()) {
            for (int e = 0; e < bb.size(); e++) {
                int check1 = bb.get(e);
                if (aa.contains(check1)) {
                    kk.add(check1);
                }
            }
            
        } else {
            for (int f = 0; f < aa.size(); f++) {
                int check2 = aa.get(f);
                if (bb.contains(check2)) {
                    kk.add(check2);
                }
            }
        }
        System.out.println(kk.get(kk.size() - 1 - (k - 1)));
    }
}