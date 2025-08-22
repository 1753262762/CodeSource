public class InterfaceDemo {
    public static void main(String[] args) {
        Person Tom = new Student("Tom");
        Tom.Run();
        Tom.SayHello();
    }
}

interface Person {
    void Run();

    String GetName();

    default void SayHello() {
        System.out.println("Hello,I am " + GetName());
    }
}

class Student implements Person {
    private String name;

    public Student(String name) {
        this.name = name;
    }

    @Override
    public void Run() {
        System.out.println(this.name + " is running");
    }

    @Override
    public String GetName() {
        return this.name;
    }
}