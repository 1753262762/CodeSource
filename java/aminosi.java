import java.util.Scanner;

public class aminosi {

    public static void main(String[] args) {
        int size = 10;
        int data[] = new int[size + 1];
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < data.length - 1; i++) {
            data[i] = scanner.nextInt();
        }
        int tot = 0;
        int ans = 0;
        for (int i : data) {
            tot += data[i];
            ans = max(ans, data[i]);
        }
        System.out.println(tot);
        System.out.println(ans);
        scanner.close();
    }

    public static int max(int x, int y) {
        return x >= y ? x : y;
    }
}