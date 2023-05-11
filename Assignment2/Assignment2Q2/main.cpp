#include <iostream>
#include <iomanip>
using namespace std;

class Employee {
protected:
    double weekly_salary;
    double vacation_days_left;
    double weekly_healthcare_contributions;
    double hours_worked; 
    double previous_vacation_hours;
    double used_vacation_hours;

public:
    Employee(double hours_worked, double previous_vacation_hours, double used_vacation_hours) {
        this->hours_worked = hours_worked;
        this->previous_vacation_hours = previous_vacation_hours;
        this->used_vacation_hours = used_vacation_hours;
    }

    double calculate_weekly_salary() {
        return weekly_salary;
    }
    double calculate_vacation_days_left() {
        return vacation_days_left;
    }
    double calculate_weekly_healthcare_contributions() {
        return weekly_healthcare_contributions;
    }

    double get_weekly_salary() const { return weekly_salary; }
    double get_vacation_days_left() const { return vacation_days_left; }
    double get_weekly_healthcare_contributions() const { return weekly_healthcare_contributions; }
};

class Professional : public Employee {
private:
    double annual_salary;
public:
    Professional(double annual_salary, double previous_vacation_hours, double used_vacation_hours) :
        Employee(40, previous_vacation_hours, used_vacation_hours) {
        this->annual_salary = annual_salary;
        weekly_salary = calculate_weekly_salary();
        vacation_days_left = calculate_vacation_days_left();
        weekly_healthcare_contributions = calculate_weekly_healthcare_contributions();
        }

    // Rule: Professional's weekly salary is the annual salary divided by 52 weeks in a year
    double calculate_weekly_salary() {
        return annual_salary / 52;
    }

    // Rule: A "day" of vacation is 8 hours
    double calculate_vacation_days_left() {
        // Rule Prof vacation days are simply subtracted from total as they do not accrue
        return (previous_vacation_hours - used_vacation_hours) / 8;
    }

    double calculate_weekly_healthcare_contributions() {
        // Rule: Prof healthcare rate is 2.5% of weekly salary
        static const double healthcare_percentage = .025;
        return weekly_salary * healthcare_percentage;
    }

};

class Nonprofessional : public Employee {
private:
    double hourly_wage;
public:
    Nonprofessional(double hourly_wage, double hours_worked, double previous_vacation_hours, double used_vacation_hours) :
        Employee(hours_worked, previous_vacation_hours, used_vacation_hours) {
        this->hourly_wage = hourly_wage;
        weekly_salary = calculate_weekly_salary();
        vacation_days_left = calculate_vacation_days_left();
        weekly_healthcare_contributions = calculate_weekly_healthcare_contributions();
        }

    double calculate_weekly_salary() {
        // Rule: Nonprof get paid vacation hours
        return (hours_worked + used_vacation_hours) * hourly_wage;
    }

    // Rule: A "day" of vacation is 8 hours
    double calculate_vacation_days_left() {
        static const double vacation_accrued_per_hour = 0.05;
        // Rule Nonprof vacation days are accrued per hour worked and also subtracted if used
        return (previous_vacation_hours - used_vacation_hours + hours_worked * vacation_accrued_per_hour) / 8;
    }

    double calculate_weekly_healthcare_contributions() {
        // Rule: Prof healthcare rate is 1.25% of weekly salary
        static const double healthcare_percentage = .0125;
        // Rule: If nonprofessional worked less than 40 hours (not including vacation), then no healthcare is added
        if ((hours_worked + used_vacation_hours) >= 40) {
            return (hours_worked + used_vacation_hours) * hourly_wage * healthcare_percentage;
        } else {
            return 0;
        }
    }

};

int main() {
    Professional prof(50000, 80, 16);
    cout << fixed << setprecision(2);
    cout << "Professional's weekly salary: $" << prof.get_weekly_salary() << endl;
    cout << "Professional's vacation days left: " << prof.get_vacation_days_left() << endl;
    cout << "Professional's weekly healthcare contributions: $" << prof.get_weekly_healthcare_contributions() << endl;

    Nonprofessional nonprof(15, 35, 40, 4);
    cout << "Nonprofessional's weekly salary: $" << nonprof.get_weekly_salary() << endl;
    cout << "Nonprofessional's vacation days left: " << nonprof.get_vacation_days_left() << endl;
    cout << "Nonprofessional's weekly healthcare contributions: $" << nonprof.get_weekly_healthcare_contributions() << endl;

    return 0;
}