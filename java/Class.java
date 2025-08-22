public class Class {
    public static void main(String args[]) {
        Person xiaoming = new Person("xiaoming", 18);
        System.out.println("Name: " + xiaoming.GetName());
        System.out.println("Age: " + xiaoming.GetAge());
        xiaoming.SetAge(20);
        xiaoming.SetName("xiaohong");
        System.out.println("Name: " + xiaoming.GetName());
        System.out.println("Age: " + xiaoming.GetAge());
    }
}

class Person {
    private String name;
    private int age;

    public Person() {
        this("Unknown", 0);
    }

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public int GetAge() {
        return this.age;
    }

    public String GetName() {
        return this.name;
    }

    public void SetAge(int age) {
        if (age < 0 || age > 120) {
            throw new IllegalArgumentException(name + " age should be between 0 and 120", null);
        }
        this.age = age;
    }

    public void SetName(String name) {
        if (name == null || name.isBlank()) {
            throw new IllegalArgumentException("Name should not be null or empty", null);
        }
        this.name = name.strip();
    }

}

class Student extends Person {
    private int score;

    public Student(String name, int age, int score) {
        super(name, age);
        this.score = score;
    }

    public void SetScore(int score) {
        this.score = score;
    }

    public int GetScore() {
        return score;
    }
}
