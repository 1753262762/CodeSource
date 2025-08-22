public class swap {
    public static void main(String[] args) {
        int a=1,b=2;
        sovle(a,b);
        System.out.println(a+" "+b);
    }
    public static void sovle(int  x,int y){
        int tmp=y;
        y=x;
        x=tmp;
    }
}
