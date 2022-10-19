#include "Employee.h"

//Constructor for Professional
//@Params: int healthcare %, salary, vacation days (assuming professional employees have a set number of vacation days)
Professional::Professional(int hc, int sl, int vac)
{
    healthcarePercent = hc;
    salary = sl;
    vacation = vac;
}

//Prints salary, healthcare contributions, vacation days
//Utilizes setprecision(2) to keep the ouput to 2 decimal places
void Professional::PrintEmployeeData() const{ 
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << "Employee's weekly salary: $" << WeeklySalary() << std::endl;
    std::cout << "Employee's healthcare contributions: $" << HealthCareContribution() << std::endl;
    std::cout << "Employee's total vacation days: " << Vacation() << std::endl;
}

//Computes and returns weekly salary from monthly (monthly salary / 4 weeks)
double Professional::WeeklySalary() const
{
    return salary/4;
}

//Computes and returns healthcare contributions ((healthcare percent * salary)/100)
double Professional::HealthCareContribution() const
{
    return (healthcarePercent * WeeklySalary())/100;
}

//Simply returns the employees vacation days
double Professional::Vacation() const
{
    return vacation;
}