import java.util.Arrays;
import java.util.Scanner;

public class tmp {
    public static void main(String[] args) {
        char ss;
        ss = '嗯';
        System.out.println(ss);// print line
        String s2;
        s2 = "测试内容";
        System.out.println(s2);
        final int MAXN = 10000;
        System.out.println(MAXN);
        final var MINX = -1e5;
        System.out.println(MINX);
        var ss1 = "hello";
        var ss2 = ss1;
        ss1 = "world";
        System.out.println(ss1);
        System.out.println(ss2);
        int[] x = { 1, 2, 3, 4, 5 };
        for (var i : x) {
            System.out.println(i);
        }
        System.out.println(Arrays.toString(x));
        Scanner scanner = new Scanner(System.in);
        System.out.println("please input string");
        var name = scanner.nextLine();
        System.out.println(name);
        System.out.println("please input int");
        var age = scanner.nextInt();
        System.out.print(age);
    }
}