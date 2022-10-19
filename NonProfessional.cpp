#include "Employee.h"

//Constructor for NonProfessional
//@Params: int healthcare %, salary, vacation days, double hours worked
NonProfessional::NonProfessional(int hc, int sl, int vac, double hrs)
{
    healthcarePercent = hc;
    salary = sl;
    vacation = vac;
    hoursWorked = hrs;
}

//Prints salary, healthcare contributions, vacation days
//Utilizes setprecision(2) to keep the ouput to 2 decimal places
void NonProfessional::PrintEmployeeData() const
{
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << "Employee's weekly salary: $" << WeeklySalary() << std::endl;
    std::cout << "Employee's health care contributions: $" << HealthCareContribution() << std::endl;
    std::cout << "Employee's total earned vacation time: " << Vacation() << " hours." << std::endl;
}

//Computes and returns weekly salary (salary * hours worked)
double NonProfessional::WeeklySalary() const
{
    return salary * hoursWorked;
}

//Computes and returns healthcare contributions ((healthcare percent * (salary * hours worked)/100)
double NonProfessional::HealthCareContribution() const
{
    return (healthcarePercent*(salary*hoursWorked))/100;
}

//Computes and returns vaction time (hours worked / divisor that determines vacation time earned)
double NonProfessional::Vacation() const
{
    return hoursWorked/vacation;
}