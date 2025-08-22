public class CheckIncome {
    public static void main(String[] args) {
        Income[] one_preson = new Income[] {
                new Income(3000),
                new SalaryIncome(5000),
                new StateConciSpecialAllowance(1000),
        };
        System.out.println("Total Income: " + totalIncome(one_preson));
    }

    public static double totalIncome(Income... incomes) {
        double res = 0;
        for (Income income : incomes) {
            res += income.GetTax();
        }
        return res;
    }
}

class Income {
    protected double income;

    public Income(double income) {
        this.income = income;
    }

    public double GetTax() {
        return income * 0.1;
    }
}

class SalaryIncome extends Income {
    public SalaryIncome(double income) {
        super(income);
    }

    @Override

    public double GetTax() {
        if (income <= 5000) {
            return 0;
        }
        return (income - 5000) * 0.2;
    }
}

class StateConciSpecialAllowance extends Income {
    public StateConciSpecialAllowance(double income) {
        super(income);
    }

    @Override

    public double GetTax() {
        return 0;
    }
}
