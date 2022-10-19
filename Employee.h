#pragma once
#include <iostream>
#include <iomanip>
class Employee
{
public:
    //Declarations for my abstract functions
    virtual void PrintEmployeeData() const = 0;
	virtual double WeeklySalary() const = 0;
	virtual double HealthCareContribution() const = 0;
	virtual double Vacation()const = 0;
protected:
    //Creating variables for use in the derived classes
	int salary, healthcarePercent, vacation;
    double hoursWorked;
};
//Derviving Professional from Employee class
class Professional : public Employee
{
public:
    //Constructor for Professional
    //@Params: int healthcare %, salary, vacation days (assuming professional employees have a set number of vacation days)
    Professional(int hc, int sl, int vac);
    //Professional versions of the virtual functions from Employee
    void PrintEmployeeData() const override;
    double WeeklySalary()const override;
    double HealthCareContribution()const override;
    double Vacation()const override;
};
//Deriving NonProfessional from Employee class
class NonProfessional :
    public Employee
{
public:
    //Constructor for NonProfessional
    //@Params: int healthcare %, salary, vacation days, double hours worked
    NonProfessional(int hc, int sl, int vac, double hrs);
    //NonProfessional versions of the virtual functions from Employee
    void PrintEmployeeData()const override;
    double WeeklySalary()const override;
    double HealthCareContribution()const override;
    double Vacation()const override;
};


