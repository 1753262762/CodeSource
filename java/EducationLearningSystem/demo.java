package EducationLearningSystem;

import java.io.IOException;
import java.util.Scanner;

public class demo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        for (String arg : args) {
            if ("-version".equals(arg)) {
                System.out.println("Version 1.0");
                break;
            } else if ("-help".equals(arg)) {
                System.out.println("Usage: java demo [-version|-help]");
                System.out.println("-version: print version information");
                System.out.println("-help: print usage information");
                break;
            }
        }
        Subject Major = new Subject();
        while (true) {
            System.out.println("please enter the exam of your score:");
            double input = scanner.nextDouble();
            if (input == 0) {
                scanner.close();
                break;
            }
            Major.SetScoreExam(input);
            Major.OutKillScoreLine();
            System.out.println("enter someting to continue or enter 0 to exit:");
            String input2 = scanner.next();
            if ("0".equals(input2)) {
                scanner.close();
                break;
            }
            ClearScreen();
        }
    }

    public static void ClearScreen() {
        try {
            if (System.getProperty("os.name").contains("Windows")) {
                new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
            } else {
                new ProcessBuilder("bash", "-c", "clear").inheritIO().start().waitFor();
            }
        } catch (IOException | InterruptedException e) {
            System.out.println("can not clear screen");
            e.printStackTrace();
        }
    }
}

class Subject {
    private double Percentage_ScoreExam;
    private double Percentage_ScoreClass;

    public Subject(double Percentage_ScoreExam) {
        this.Percentage_ScoreExam = Percentage_ScoreExam;
        this.Percentage_ScoreClass = 1 - Percentage_ScoreExam;
    }

    public Subject() {
    }

    public void SetScoreExam(double Percentage_ScoreExam) {
        if (Percentage_ScoreExam < 0) {
            throw new IllegalArgumentException("Score should be greater than 0");
        } else if (Percentage_ScoreExam >= 0 && Percentage_ScoreExam < 1) {
            this.Percentage_ScoreExam = Percentage_ScoreExam;
            this.Percentage_ScoreClass = 1 - this.Percentage_ScoreExam;
        } else if (Percentage_ScoreExam >= 1 && Percentage_ScoreExam <= 100) {
            this.Percentage_ScoreExam = Percentage_ScoreExam / 100;
            this.Percentage_ScoreClass = 1 - this.Percentage_ScoreExam;
        } else if (Percentage_ScoreExam > 100) {
            throw new IllegalArgumentException("Score should be less than 100");
        }
    }

    public double CheckLowestSocreInExam(double ScoreClass) {
        return (60 - Percentage_ScoreClass * ScoreClass) / Percentage_ScoreExam;
    }

    public double CheckLowestSocreInExam() {
        return CheckLowestSocreInExam(90);// 无传参则默认为90分,即老师宽宏大量
    }

    public void OutKillScoreLine() {
        double res = CheckLowestSocreInExam();
        if (res < 0) {
            System.out.println("Ez for pass! Only becareful for missing exams!");// 有手就行
            return;
        }
        System.out.println("Kill Score Line: " + res);
    }
}